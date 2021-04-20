#include "Types.h"
#include "Entity.h"
#include <vector>
#include<chrono>
#include<iostream>

namespace Engine
{
	class World
	{
	private:
		Time Delta;
		Vector2f Gravity = { 0, -9.81 };
		//TODO : Implement World Bounds
		Vector2f Bounds = { 0,0 };
		std::vector<Entity*> Entities;
		Vector2i ScreenResolution = { 1920,1080 };
	public:

		//////////////////////////////////////////////////////
		// Init World
		// TODO : Implement more World Constructors if needed
		// @param Bounds Takes bounds for the world
		//////////////////////////////////////////////////////
		World();
		World(Vector2f);
		~World();
		int Step();
		void AddEntity(Entity*);
		std::vector<Entity*> GetEntities();
		Vector2f CalcForce(Entity*);
		void CalcPosition(Entity*);
		void SetGravity(Vector2f);
	};
}