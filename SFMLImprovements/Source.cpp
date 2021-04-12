
#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>
#include<chrono>
#include"../Engine/Include/World.h"

//template <typename T>
//std::string ToString(T x)
//{
//	std::string s;
//	s = (char*) x;
//	return s;
//}

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pendulum");
	window.setFramerateLimit(30);
	sf::CircleShape shape[10];
	sf::Font font;
	font.loadFromFile("Ubuntu-Light.ttf");
	sf::Text PosText;
	PosText.setFont(font);
	PosText.setPosition(10, 10);
	PosText.setCharacterSize(50);
	PosText.setFillColor(sf::Color::Cyan);
	World world;

	std::chrono::time_point<std::chrono::steady_clock> PreviousTime;

	for (int i = 0; i < 10; i++)
	{
		shape[i].setRadius(5 + rand()%10);
		shape[i].setFillColor(sf::Color::Green);
		shape[i].setPosition(950, 440);
		Entity* e = new Entity();
		e->Position(rand()%1910, rand()%150);
		e->Mass = 10;
		world.AddEntity(e);
	}

	int Radius = 100, FrameNo=0;

	PreviousTime = std::chrono::steady_clock::now();
	while (window.isOpen())
	{
		auto CurrentTime = std::chrono::steady_clock::now();
		auto Duration = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - PreviousTime);
		PreviousTime = CurrentTime; 
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		PosText.setString("Frame No" + std::to_string(FrameNo++ % 60));
		
		world.Step(Duration.count());
		for (int i=0;i < world.GetEntities().size(); i++)
			shape[i].setPosition(world.GetEntities()[i]->Position.x,-world.GetEntities()[i]->Position.y);

		window.clear();
		window.draw(PosText);
		for(auto ball : shape)
			window.draw(ball);
		


		window.display();
	}

	return 0;
}