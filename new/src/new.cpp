#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "eclpsr");

	sf::Texture texture;

	if (!texture.loadFromFile("src/red.png"))
	{
		std::cout << "Error loading red texture ;(" << std::endl;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

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


		window.clear();

		window.draw(sprite);

		window.display();
		}
}
