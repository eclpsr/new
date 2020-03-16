#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "eclpsr");

	while ( window.isOpen( ) )
	{
		sf::Event event;

		while ( window.pollEvent( event ) )
		{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();

					break;

				case sf::Event::Resized:
					std::cout << event.size.width << " : " << event.size.height << std::endl;

					break;

				case sf::Event::LostFocus:
					std::cout << "Lost Focus" << std::endl;

					break;

				case sf::Event::GainedFocus:
					std::cout << "Gained focus" << std::endl;

					break;
				}
			}

		window.clear();
		window.display();
		}
}
