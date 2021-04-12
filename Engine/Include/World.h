#include "Types.h"
#include "Entity.h"
#include <vector>
#include<chrono>
#include<iostream>

class World
{
private:
	Time Delta;
	Vector2f Gravity = { 0, -9.81};
	//TODO : Implement World Bounds
	Vector2f Bounds = { 0,0 };
	std::vector<Entity*> Entities;
public:

	//////////////////////////////////////////////////////
	// Init World
	// TODO : Implement more World Constructors
	// @param Bounds Takes bounds for the world
	//////////////////////////////////////////////////////
	World();
	World(Vector2f);
	~World();
	int Step(int dt);
	void SetDelta(long);
	void AddEntity(Entity*);
	std::vector<Entity*> GetEntities();
	Vector2f CalcForce(Entity*);
	void CalcPosition(Entity*);
	void SetGravity(Vector2f);
};
