#include "Include\World.h"
World::World()
{

}

World::World(Vector2f NewBounds)
{
	Bounds = NewBounds;
}

World::~World()
{
	for(auto entity : Entities)
	{
		free(entity);
	}
}

//newDelta : param in milliseconds
int World::Step()
{
	
	//SetDelta(newDelta);
	
	//if(Delta >= 1000/60)
	for (Entity* entity : Entities)
	{
		CalcPosition(entity);
	}

	Delta.Step();
	std::cout << Delta << std::endl;
	return 0;
}


void World::AddEntity(Entity* NewEntity)
{
	Entities.push_back(NewEntity);
}


std::vector<Entity*> World::GetEntities()
{
	return Entities;
}

Vector2f World::CalcForce(Entity* Body)
{
	return Gravity * Body->Mass;
}

///
/* \breif
* ToDo: dt = currentFrameTime - PreviousFrameTime will work as it can tell us if the next step is happening after 1 sec or not
*/
///
void World::CalcPosition(Entity* entity)
{
	Vector2f accln = CalcForce(entity) / entity->Mass;//{ entity->Mass / Gravity.x , entity->Mass / Gravity.y };
	entity->Velocity += accln * Delta; //{ entity->Velocity.x + accln.x * delta, entity->Velocity.y + accln.y * delta };
	entity->Position += entity->Velocity * Delta * (1920/10); //1920/10 is actually screen resolution / length in meters you assume your world is being represented on screen
	
}

void World::SetGravity(Vector2f NewGravity)
{
	Gravity = NewGravity;
}
