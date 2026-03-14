#pragma once
#include "IState.h"
class S_NEEDS_CLEANING : public IState
{
	// Inherited via IState
	void Update() override;
	void Render() override;
	void Exit() override;
	void Enter() override;
};

