#include "Include\Collider.h"
#include<iostream>

Engine::Collider::Collider()
{
	Verticies = new std::vector<Vector2i>();
}

Engine::Collider::Collider(std::vector<Vector2i>&& NewVerticies)
{
	free(Verticies);
	Verticies = &NewVerticies;
	for (auto x : *Verticies)
		std::cout << x.x << " ";
}

void Engine::Collider::SetVerticies(std::vector<Vector2i>&& NewVerticies)
{
	Verticies->clear();
	Verticies = &NewVerticies;
	for (auto x : *Verticies)
		std::cout << x.x << " ";
}
