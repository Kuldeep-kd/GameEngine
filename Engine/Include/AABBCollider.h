#include "Collider.h"

#ifndef AABBCollider
#define AABBCollider
namespace Engine
{
	class AABB : public Collider
	{
	public:
		AABB(std::vector<Vector2i>&&);

	};
}
#endif