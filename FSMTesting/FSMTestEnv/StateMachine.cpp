#include "StateMachine.h"
#include "IState.h"

#include "S_BREWING.h"
#include "S_CLEANING.h"
#include "S_IDLE.h"
#include "S_LOW_BEAN.h"
#include "S_LOW_WATER.h"
#include "S_NEEDS_CLEANING.h"
#include "CoffeeMachine.h"


void StateMachine::Update()
{
	m_currentState->Update();

	if (m_currentState->IsComplete())
	{
		if (m_currentState == m_states[IDLE])
		{


			if (m_currentState->Exit() == BREWING)
			{

			}

			if (m_cMachine->GetWater() < WATER_PER_CUP)
			{
				m_currentState = m_states[LOW_WATER]; // A basic state change indication
			}

			if (m_cMachine->GetBeans() < BEANS_PER_CUP)
			{
				m_currentState = m_states[LOW_BEANS]; // A basic state change indication
			}

			if (m_cMachine->GetCups() > CLEANING_THRESHOLD_CUPS * 2)
			{
				m_currentState = m_states[NEEDS_CLEANING];
			}
		}
		else
		{
			m_currentState = m_states[IDLE];
		}
	}
}

void StateMachine::Render()
{
	m_currentState->Render();
}

void StateMachine::SetState(MachineState type)
{
	m_currentState = m_states[type];
}

MachineState StateMachine::GetState()
{
	for (int i = 0; i < MAX; i++)
	{
		if (m_states[i] == m_currentState)
		{
			return (MachineState)i;
		}
	}
}

StateMachine::StateMachine(CoffeeMachine* cMac) : m_currentState(), m_states(new IState*[(int)MachineState::MAX]), m_cMachine(cMac)
{
	IState* StateBrewing = new S_BREWING();
	IState* StateCleaning = new S_CLEANING();
	IState* StateLowBean = new S_LOW_BEAN();
	IState* StateLowWater = new S_LOW_WATER();
	IState* StateNeedsCleaning = new S_NEEDS_CLEANING();
	IState* StateIdle = new S_IDLE();

	m_states[BREWING] = StateBrewing;
	m_states[CLEANING] = StateCleaning;
	m_states[LOW_BEANS] = StateLowBean;
	m_states[LOW_WATER] = StateLowWater;
	m_states[NEEDS_CLEANING] = StateNeedsCleaning;
	m_states[IDLE] = StateIdle;

	m_currentState->Enter(cMac);
}

StateMachine::~StateMachine()
{
	for (int i = 0; i < MAX; i++)
	{
		if (m_states[i] && (i != MAX))
		{
			delete m_states[i];
		}
	}

	if (m_currentState)
	{
		delete m_currentState;
	}

	if (m_cMachine)
	{
		delete m_cMachine;
	}

}
