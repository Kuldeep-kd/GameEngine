#pragma once
#include "Types.h"

class Entity
{
private:
public:
	Vector2f Velocity, Position, Center, Force;
	double Mass=0;

	Entity();
	void SetVelocity(Vector2f*);
	void SetPosition(Vector2f*);
	void SetCenter(Vector2f*);
	void SetForce(Vector2f*);
	void SetMass(double);

	Vector2f* GetVelocity();
	Vector2f* GetPosition();
	Vector2f* GetCenter();
	Vector2f* GetForce();
	double GetMass();
};