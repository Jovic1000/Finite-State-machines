#include "StateMachine.h"
#include "IState.h"

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
}

StateMachine::~StateMachine()
{
}
