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


int World::Step(int dt)
{
	auto CurrentTime = std::chrono::steady_clock::now();
	auto Duration = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - PreviousTime);
	
	//std::cout << Duration.count()<<" ";
	
	//if(Duration.count() >= 1000/60)
		for (Entity* entity : Entities)
		{
			CalcPosition(entity);
			PreviousTime = std::chrono::steady_clock::now();
		}

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
	return Vector2f{ 0,0 };
}

///
/* \breif
* ToDo: dt = currentFrameTime - PreviousFrameTime will work as it can tell us if the next step is happening after 1 sec or not
*/
///
void World::CalcPosition(Entity* entity)
{
	Vector2f accln = Gravity / entity->Mass;//{ entity->Mass / Gravity.x , entity->Mass / Gravity.y };
	entity->Velocity += accln * delta; //{ entity->Velocity.x + accln.x * delta, entity->Velocity.y + accln.y * delta };
	entity->Position += entity->Velocity * delta;
}

void World::SetGravity(Vector2f NewGravity)
{
	Gravity = NewGravity;
}
