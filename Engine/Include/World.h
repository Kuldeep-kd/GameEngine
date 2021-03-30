#include "Types.h"
#include "Entity.h"
#include <vector>


class World
{
private:
	int delta = 1;
	Vector2f Gravity = { 0, -9.81};
	std::vector<Entity*> Entities;
public:

	World() {};
	~World();
	int Init();
	int Step(int dt);
	void AddEntity(Entity*);
	Vector2f CalcForce(Entity*);
	void SetGravity(Vector2f);
};