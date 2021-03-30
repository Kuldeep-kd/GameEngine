
#include "Types.h"
#include "Entity.h"



class World
{
private:
	int delta = 0;
	Vector2f Gravity = { 0, 9.81};

public:

	int Init();
	int Step(int dt);
	int CalcForce(Entity*);
	void SetGravity(Vector2f);
};