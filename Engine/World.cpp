#include "Include\World.h"

World::~World()
{
	for(auto entity : Entities)
	{
		free(entity);
	}
}

int World::Init()
{
	
	return 0;
}

int World::Step(int dt)
{
	for (Entity* entity : Entities)
	{
		Vector2f accln = Gravity / entity->Mass;//{ entity->Mass / Gravity.x , entity->Mass / Gravity.y };
		entity->Velocity += accln * delta; //{ entity->Velocity.x + accln.x * delta, entity->Velocity.y + accln.y * delta };
		entity->Position += entity->Velocity*delta;
	}

	return 0;
}

void World::AddEntity(Entity* NewEntity)
{
	Entities.push_back(NewEntity);
}

Vector2f World::CalcForce(Entity* Body)
{
	return Vector2f{ 0,0 };
}

void World::SetGravity(Vector2f NewGravity)
{
	Gravity = NewGravity;
}
