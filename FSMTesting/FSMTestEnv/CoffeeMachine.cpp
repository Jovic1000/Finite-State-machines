#include "CoffeeMachine.h"
#include "ConsoleDefines.h"
#include "CoffeeTypes.h"
#include "Coffee.h"
#include "User.h"
#include "StateMachine.h"
#include <iostream>


CoffeeMachine::CoffeeMachine() : m_stateMachine(this), m_waterLevel(0), m_cupsMade(0), m_coffeeBeans(0)
{
}

CoffeeMachine::~CoffeeMachine()
{
}

void CoffeeMachine::Init()
{
    m_stateMachine.SetState(IDLE);
}

Coffee CoffeeMachine::MakeCoffee() 
{
    using std::cout, std::endl;
    cout << "Attempting to make coffee...\n";
    


    return Coffee(CoffeeType::NONE);
}

Coffee CoffeeMachine::BrewCoffee()
{   

    m_stateMachine.SetState(BREWING); // temp sets state to brewing

    m_waterLevel -= WATER_PER_CUP;
    m_coffeeBeans -= BEANS_PER_CUP;
    m_cupsMade += 1;

    m_stateMachine.Render();

    // After brewing, transition back to idle or require cleaning
    if (m_cupsMade >= CLEANING_THRESHOLD_CUPS) 
    {
        m_stateMachine.SetState(NEEDS_CLEANING);
        m_stateMachine.Render();
    } 
    else
    {
        m_stateMachine.SetState(IDLE); // Back to idle if no immediate cleaning needed
    }
    
    // Seems like we could use a new selection to set the coffee type, huh?
    return Coffee(Americano);
}

void CoffeeMachine::DisplayStatus() {
    std::cout << "\n--- Coffee Machine Status ---\n";
    std::cout << "State: " << StateToString(m_stateMachine.GetState()) << "\n";
    std::cout << "Water: " << m_waterLevel << "/" << MAX_WATER_CAPACITY << " ml\n";
    std::cout << "Coffee Beans: " << m_coffeeBeans << "/" << MAX_BEAN_CAPACITY << " g\n";
    std::cout << "Cups Made Since Last Clean: " << m_cupsMade << "\n";
    std::cout << "---------------------------\n" << std::endl;
}

// Function to convert MachineState enum to string for display
std::string CoffeeMachine::StateToString(MachineState state) 
{
    switch (state) {
        case MachineState::IDLE: 
            return "IDLE";
        case MachineState::LOW_WATER: 
            return "LOW_WATER";
        case MachineState::LOW_BEANS: 
            return "LOW_BEANS";
        case MachineState::BREWING: 
            return "BREWING";
        case MachineState::CLEANING: 
            return "CLEANING";
        case MachineState::NEEDS_CLEANING: 
            return "NEEDS_CLEANING";
        default: 
            return "UNKNOWN";
    }
}

void CoffeeMachine::DisplayUserMessage()
{
    std::cout << "--- Coffee Machine Menu ---\n";
    std::cout << "1. Make Coffee\n";
    std::cout << "2. Add Water\n";
    std::cout << "3. Add Coffee Beans\n";
    std::cout << "4. Clean Machine\n";    
    std::cout << "5. Display Status Information\n";
    std::cout << "6. Exit\n";
}

void CoffeeMachine::UserInteract(int input, const User& user)
{
    system(cls);
    switch (input)
    {
        case 1:
            MakeCoffee();
            break;
        case 2:
        {
            std::cout << "Enter amount of water to add (ml): ";
            int waterML = user.GetInput();
            if (waterML > 0)
            {
                AddWater(waterML);
            }
            break;
        }
        case 3:
        {
            int beansG = user.GetInput();
            if (beansG > 0)
            {
                AddBeans(beansG);
            }
            break;
        }
        case 4:
            CleanMachine();
            break;
        case 5:
            DisplayStatus();
            break;
        case 6:
            std::cout << "Exiting Coffee Machine. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
    }
}

int CoffeeMachine::GetWater()
{
    return m_waterLevel;
}

int CoffeeMachine::GetBeans()
{
    return m_coffeeBeans;
}

int CoffeeMachine::GetCups()
{
    return m_cupsMade;
}
