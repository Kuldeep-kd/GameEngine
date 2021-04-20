#include<vector>
#include"Entity.h"

#ifndef COLLIDER
#define COLLIDER

namespace Engine
{
	class Collider
	{
	public:
		std::vector<Vector2i> *Verticies;

		Collider();
		Collider(std::vector<Vector2i>&&);
		void SetVerticies(std::vector<Vector2i>&&);


	};

	/*bool IsColliding(Entity e1, Entity e2)
	{

	}*/
}

#endif