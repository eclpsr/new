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

				}
			}

		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) )
		{
			std::cout << "Jump Player" << std::endl;
		}

		window.clear();
		window.display();
		}
}
