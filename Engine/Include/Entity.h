#pragma once
#include "Types.h"
#include "Collider.h"

namespace Engine
{
	//I don`t really understand why the Collider declaration is needed here
	//Cuz Collider.h should do it for us
	//Pragma once not working
	
	//class Collider;

	class Entity
	{
		struct EntityProperties
		{
			Vector2f Velocity, Position, Center, Force;
			EntityProperties() 
			{
				Velocity = { 0,0 };
				Position = { 0,0 };
				Center = { 0,0 };
				Force = { 0,0 };
			}
		};

	public:
		Vector2f *Velocity, *Position, *Center, *Force;
		Collider *collider;
		bool IsStatic = false;
		double Mass = 0;

		Entity();
		Entity(EntityProperties&);

		void SetVelocity(Vector2f*);
		void SetPosition(Vector2f*);
		void SetCenter(Vector2f*);
		void SetForce(Vector2f*);
		void SetMass(double);
		void SetCollider(Collider);
		void SetStatic(bool);

		Vector2f* GetVelocity();
		Vector2f* GetPosition();
		Vector2f* GetCenter();
		Vector2f* GetForce();
		Collider GetCollider(Collider);
		double GetMass();
	};
}