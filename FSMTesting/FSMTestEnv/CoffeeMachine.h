#pragma once
#include "CoffeeMachineStates.h"
#include <string>

class User;
class Coffee;
class CoffeeMachine
{
public:
    CoffeeMachine();
    ~CoffeeMachine();
    
    void DisplayUserMessage();
    void UserInteract(int input, const User& user);

private:

    const int WATER_PER_CUP = 150; // ml
    const int BEANS_PER_CUP = 20;  // grams
    const int MAX_WATER_CAPACITY = 1000; // ml
    const int MAX_BEAN_CAPACITY = 500; // grams
    const int CLEANING_THRESHOLD_CUPS = 5;
        
    Coffee MakeCoffee();
    bool CheckCanBrew();
    Coffee BrewCoffee();
    void AddWater(int amountML);
    void AddBeans(int amountG);
    void CleanMachine();
    void DisplayStatus();
    std::string StateToString(MachineState state);
    
    MachineState m_currentState;
    int m_waterLevel = 500;  // ml
    int m_coffeeBeans = 200; // grams
    int m_cupsMade = 0;
};

