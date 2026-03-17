#include "S_NEEDS_CLEANING.h"
#include "CoffeeMachine.h"
#include <iostream>

void S_NEEDS_CLEANING::Update()
{
}

void S_NEEDS_CLEANING::Render()
{
	std::cout << "Machine needs cleaning soon!\n";
}

MachineState S_NEEDS_CLEANING::Exit()
{
	return IDLE;
}

void S_NEEDS_CLEANING::Enter(CoffeeMachine* cMac)
{
	m_cMachine = cMac;
}

bool S_NEEDS_CLEANING::IsComplete()
{
	return m_stateComplete;
}
