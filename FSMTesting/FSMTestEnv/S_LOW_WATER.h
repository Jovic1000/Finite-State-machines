#pragma once
#include "IState.h"
class S_LOW_WATER : public IState
{
public:
	// Inherited via IState
	void Update() override;
	void Render() override;
	void Enter(CoffeeMachine* cMac) override;
	bool IsComplete();

	MachineState Exit() override;
private:
	bool m_stateComplete;
	CoffeeMachine* m_cMachine;

};

