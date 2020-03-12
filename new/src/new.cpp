#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "eclpsr");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch ( event.type )
			{
			case sf::Event::Closed:
				window.close( );
				break;

			case sf::Event::KeyPressed:
				std:: cout << "Key pressed" << std::endl;

				switch (event.key.code)
					{
					case sf::Keyboard::A:
						std::cout << "A" << std::endl;
						break;
					}
				break;
				case sf::Event::KeyReleased:
					std::cout << "Key has been released" << std::endl;
					switch (event.key.code)
					{
					case sf::Keyboard::J:
						std::cout << "J RELEASED" << std::endl;
						break;
					}
				break;

			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}
