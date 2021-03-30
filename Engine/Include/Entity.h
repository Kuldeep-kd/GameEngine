#pragma once
#include "Types.h"

class Entity
{
private:
	Vector2f Velocity, Position, Center, Force;
	double Mass=0;

public:
	void SetVelocity(Vector2f*);
	void SetPosition(Vector2f*);
	void SetCenter(Vector2f*);
	void SetMass(double);

	Vector2f* GetVelocity();
	Vector2f* GetPosition();
	Vector2f* GetCenter();
	double GetMass();
};