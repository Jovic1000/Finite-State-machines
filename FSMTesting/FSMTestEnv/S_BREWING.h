#pragma once
#include "IState.h"
class S_BREWING : public IState
{
	// Inherited via IState
	void Update() override;
	void Render() override;
	void Exit() override;
	void Enter() override;
};

