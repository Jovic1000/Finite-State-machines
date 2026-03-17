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

    void Init();
    
    void DisplayUserMessage();
    void UserInteract(int input, const User& user);

    int GetWater();
    int GetBeans();
    int GetCups();


private:

    Coffee MakeCoffee();
    Coffee BrewCoffee();
    void AddWater(int amountML);
    void AddBeans(int amountG);
    void CleanMachine();
    void DisplayStatus();
    std::string StateToString(MachineState state);
  
    StateMachine m_stateMachine;
    int m_waterLevel = 500;  // ml
    int m_coffeeBeans = 200; // grams
    int m_cupsMade = 0;
};

