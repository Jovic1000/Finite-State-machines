#pragma once
#include "IState.h"

class S_BREWING : public IState
{
public:
	// Inherited via IState
	void Update() override;
	void Render() override;
	MachineState Exit() override;
	void Enter(CoffeeMachine* cMac) override;
	void Delay(int delay);
	bool IsComplete();

private:
	bool m_stateComplete;
	CoffeeMachine* m_cMachine;

};

