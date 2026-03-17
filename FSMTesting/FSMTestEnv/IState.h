#pragma once
#include "CoffeeMachine.h"

class CoffeeMachine;
class IState
{
public:

	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Enter(CoffeeMachine* cMac) = 0;
	virtual MachineState Exit() = 0;
	virtual bool IsComplete() = 0;

private:

};

