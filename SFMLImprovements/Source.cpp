
#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>

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
	window.setFramerateLimit(60);
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(950, 440);
	sf::Font font;
	font.loadFromFile("Ubuntu-Light.ttf");
	sf::Text PosText;
	PosText.setFont(font);
	PosText.setPosition(10, 10);
	PosText.setCharacterSize(50);
	PosText.setFillColor(sf::Color::Cyan);

	sf::Vector2f Velocity(10, 8);
	sf::Vector2i Position(960,440);
	int Radius = 100;
	float dx=2,dy=2,dt=0.015;
	sf::Time PrevTime = sf::Time::Time();


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		PosText.setString("x: "+ std::to_string(shape.getPosition().x) + "," + "y: " + std::to_string(shape.getPosition().y));
		
		
		shape.setPosition(shape.getPosition() + Velocity * dt);

		window.clear();
		window.draw(PosText);
		window.draw(shape);
		


		window.display();
	}

	return 0;
}