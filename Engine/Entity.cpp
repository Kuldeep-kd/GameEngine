#include "Include/Entity.h"
namespace Engine
{

	Entity::Entity()
	{
		Velocity = new Vector2f();
		Position = new Vector2f();
		Center = new Vector2f();
		Force = new Vector2f();
		IsStatic = false;
	}

	Entity::Entity(EntityProperties& Properties)
	{
		Velocity = new Vector2f(Properties.Velocity);
		Position = new Vector2f(Properties.Position);
		Center = new Vector2f(Properties.Center);
		Force = new Vector2f(Properties.Force);
		IsStatic = false;
	}

	void Entity::SetVelocity(Vector2f* NewVelocity)
	{
		Velocity = NewVelocity;
	}

	void Entity::SetPosition(Vector2f* NewPosition)
	{
		Position = NewPosition;
	}

	void Entity::SetCenter(Vector2f* NewCenter)
	{
		Center = NewCenter;
	}

	void Entity::SetForce(Vector2f* NewForce)
	{
		*Force += *NewForce;
	}

	void Entity::SetMass(double NewMass)
	{
		Mass = NewMass;
	}

	void Entity::SetCollider(Collider C)
	{
	}

	void Entity::SetStatic(bool NewIsStatic)
	{
		if (NewIsStatic)
		{
			if(Force != NULL)
				free(Force);
			if (Velocity!= NULL)
				free(Velocity);
		}
		else
		{
			Velocity = new Vector2f();
			Force = new Vector2f();
		}
	}

	Vector2f* Entity::GetVelocity()
	{
		return Velocity;
	}

	Vector2f* Entity::GetPosition()
	{
		return Position;
	}

	Vector2f* Entity::GetCenter()
	{
		return Center;
	}

	Vector2f* Entity::GetForce()
	{
		return Force;
	}

	Collider Entity::GetCollider(Collider C)
	{
		return Collider();
	}

	double Entity::GetMass()
	{
		return Mass;
	}

}