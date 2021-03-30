#include "Entity.h"

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

double Entity::GetMass()
{
	return Mass;
}
