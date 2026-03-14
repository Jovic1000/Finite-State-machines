#pragma once
class IState
{
public:

	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;
	virtual void Enter() = 0;

private:

};

