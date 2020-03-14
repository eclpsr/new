#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "eclpsr");

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

			    case sf::Event::MouseButtonPressed:
				std::cout << "Mouse button has been pressed" << std::endl;





				switch (event.key.code)
				{
				case sf::Mouse::Left:
					std::cout << "LEFT KEY HAS BEEN PRESSED" << std::endl;

					break;
				}

				switch (event.key.code)
				{
				case sf::Mouse::Right:
					std::cout << "Right key has been released" << std::endl;

					break;
				}
				break;


				case sf::Event::MouseButtonReleased:
					std::cout << "Mouse button has been released" << std::endl;

					break;



					case sf::Event::MouseWheelMoved:
						std::cout << "Mouse wheel has been scrolled" << std::endl;
						std::cout << event.mouseWheel.delta << std::endl;

						break;

					case sf::Event::MouseMoved:
						//std::cout << "Mouse has been moved" << std::endl;

						//std::cout << event.mouseMove.y << std::endl;

						break;

					case sf::Event::MouseEntered:
						std::cout << "Mouse has entered the window" << std::endl;

						break;

					case sf::Event::MouseLeft:
						std::cout << "Mouse has left the window" << std::endl;

						break;
			}
		}

		window.clear();
		window.display();
	}
}
