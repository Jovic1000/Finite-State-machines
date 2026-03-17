#pragma once
#include "IState.h"
#include "CoffeeMachineStates.h"

class S_IDLE : public IState
{
public:
	// Inherited via IState
	void Update() override;
	void Render() override;
	void Enter(CoffeeMachine* cMac) override;
	

	void SetNextState(MachineState newState);

	MachineState GetNextState();
	
	
	MachineState Exit() override;
	bool IsComplete();

private:

	bool m_stateComplete;
	MachineState m_nextState;
	CoffeeMachine* m_cMachine;
};

