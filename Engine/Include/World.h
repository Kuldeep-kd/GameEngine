#include "Types.h"
#include "Entity.h"
#include <vector>
#include<chrono>
#include<iostream>

class World
{
private:
	float delta = 1;
	Vector2f Gravity = { 0, -9.81};
	//TODO : Implement World Bounds
	Vector2f Bounds;
	std::vector<Entity*> Entities;
	std::chrono::time_point<std::chrono::steady_clock> PreviousTime;
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
	void AddEntity(Entity*);
	std::vector<Entity*> GetEntities();
	Vector2f CalcForce(Entity*);
	void CalcPosition(Entity*);
	void SetGravity(Vector2f);
};