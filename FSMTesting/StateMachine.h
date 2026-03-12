#pragma once
#include "FSMTestEnv/CoffeeTypes.h"
#include "FSMTestEnv/CoffeeMachineStates.h"

class IState;
class StateMachine
{
public:

	void Update();
	void Render();
	void SetState(CoffeeType type);
	IState* GetState();

	StateMachine();
	~StateMachine();

private:

	IState* m_currentState;
	IState** m_states;

};

