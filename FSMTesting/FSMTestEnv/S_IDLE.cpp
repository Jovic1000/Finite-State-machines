#include "S_IDLE.h"
#include "CoffeeMachine.h"
#include <iostream>

void S_IDLE::Update()
{

}

void S_IDLE::Render()
{
}

MachineState S_IDLE::Exit()
{
	return GetNextState();
}

void S_IDLE::Enter(CoffeeMachine* cMac)
{
	m_cMachine = cMac;
}

void S_IDLE::SetNextState(MachineState newState)
{
	m_nextState = newState;
}

MachineState S_IDLE::GetNextState()
{
	return m_nextState;
}

bool S_IDLE::IsComplete()
{
	return m_stateComplete;
}