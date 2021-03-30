#include "Include/Entity.h"

Entity::Entity()
{
	Velocity(0, 0);
	Position(0, 0);
	Center(0, 0);
	Force(0, 0);
}

void Entity::SetVelocity(Vector2f* NewVelocity)
{
	Velocity = *NewVelocity;
}

void Entity::SetPosition(Vector2f* NewPosition)
{
	Position = *NewPosition;
}

void Entity::SetCenter(Vector2f* NewCenter)
{
	Center = *NewCenter;
}

void Entity::SetForce(Vector2f* NewForce)
{
	Force += *NewForce;
}

void Entity::SetMass(double NewMass)
{
	Mass = NewMass;
}

Vector2f* Entity::GetVelocity()
{
	return &Velocity;
}

Vector2f* Entity::GetPosition()
{
	return &Position;
}

Vector2f* Entity::GetCenter()
{
	return &Center;
}

Vector2f* Entity::GetForce()
{
	return &Force;
}

double Entity::GetMass()
{
	return Mass;
}
