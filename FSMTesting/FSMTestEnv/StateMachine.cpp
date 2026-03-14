#include "StateMachine.h"
#include "IState.h"

#include "S_BREWING.h"
#include "S_CLEANING.h"
#include "S_IDLE.h"
#include "S_LOW_BEAN.h"
#include "S_LOW_WATER.h"
#include "S_NEEDS_CLEANING.h"

void StateMachine::Update()
{
	m_currentState->Update();
}

void StateMachine::Render()
{
	m_currentState->Render();
}

void StateMachine::SetState(CoffeeType type)
{
	m_currentState = m_states[type];
}

IState* StateMachine::GetState()
{
	return m_currentState;
}

StateMachine::StateMachine() : m_currentState(), m_states(new IState*[(int)MachineState::MAX])
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

}
