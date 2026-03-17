#include "S_LOW_WATER.h"
#include "CoffeeMachine.h"

void S_LOW_WATER::Update()
{
    std::cout << "Adding " << amountML << " ml of water...\n";
    m_waterLevel = std::min(MAX_WATER_CAPACITY, m_waterLevel + amountML);

    std::cout << "Water level is now " << m_waterLevel << " ml.\n";
    if (m_waterLevel > 0 && m_stateMachine.GetState() != )
    {
        m_stateMachine.SetState(IDLE); // Return to idle if low water was the issue
    }
}

void S_LOW_WATER::Render()
{
	"Error: Not enough water to make coffee. Please add water.\n";
}

MachineState S_LOW_WATER::Exit()
{
    return IDLE;
}

void S_LOW_WATER::Enter(CoffeeMachine* cMac)
{
	m_cMachine = cMac;
}

bool S_LOW_WATER::IsComplete()
{
	return m_stateComplete;
}
