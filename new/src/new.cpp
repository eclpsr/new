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

				case sf::Event::TextEntered:
					std::cout << "text has been entered" << std::endl;

					if ( event.text.unicode == 65 ) // A
					{
						std::cout << "Captial A has been clicked" << std::endl;
					}

					break;
				}
			}

		window.clear();
		window.display();
		}
}
