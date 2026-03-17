#pragma once
#include "CoffeeMachineStates.h"

class IState;
class CoffeeMachine;
class StateMachine
{
public:

	void Update();
	void Render();
	void SetState(MachineState type);
	MachineState GetState();

	StateMachine(CoffeeMachine* cMac);
	~StateMachine();

private:

	const int WATER_PER_CUP = 150; // ml
	const int BEANS_PER_CUP = 20;  // grams
	const int MAX_WATER_CAPACITY = 1000; // ml
	const int MAX_BEAN_CAPACITY = 500; // grams
	const int CLEANING_THRESHOLD_CUPS = 5;

	CoffeeMachine* m_cMachine;
	IState* m_currentState;
	IState** m_states;

};

