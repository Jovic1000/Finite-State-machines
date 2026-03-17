#include "S_LOW_BEAN.h"
#include "CoffeeMachine.h"

void S_LOW_BEAN::Update()
{
    std::cout << "Adding " << amount << " grams of coffee beans...\n";
    m_coffeeBeans = std::min(MAX_BEAN_CAPACITY, m_coffeeBeans + amount);

    std::cout << "Coffee beans are now " << m_coffeeBeans << " g.\n";
    if (m_coffeeBeans > 0 && m_currentState == MachineState::LOW_BEANS)
    {
        m_currentState = MachineState::IDLE; // Return to idle if low beans was the issue
    }
}

void S_LOW_BEAN::Render()
{
	"Error: Not enough coffee beans to make coffee. Please add beans.\n";
}

MachineState S_LOW_BEAN::Exit()
{
    return IDLE;
}

void S_LOW_BEAN::Enter(CoffeeMachine* cMac)
{
	m_cMachine = cMac;
}

bool S_LOW_BEAN::IsComplete()
{
    return m_stateComplete;
}