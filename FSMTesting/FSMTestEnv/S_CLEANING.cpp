#include "S_CLEANING.h"
#include "CoffeeMachine.h"

void S_CLEANING::Update()
{
    std::cout << "Initiating cleaning cycle...\n";
    m_currentState = MachineState::CLEANING; // Set to cleaning state

    // In a real FSM, this would have a delay and then transition back to IDLE
    std::cout << "Cleaning complete!\n";
    m_cupsMade = 0;
    m_currentState = MachineState::IDLE; // Return to idle after cleaning
}

void S_CLEANING::Render()
{
	"Cannot make coffee while cleaning. Please wait.\n";
}

MachineState S_CLEANING::Exit()
{
    return IDLE;
}

void S_CLEANING::Enter(CoffeeMachine* cMac)
{
	m_cMachine = cMac;
}

bool S_CLEANING::IsComplete()
{
	return m_stateComplete;
}