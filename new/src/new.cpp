#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "eclpsr");

	sf::Texture texture;
	texture.setRepeated(true);

	if (!texture.loadFromFile("src/red.png"))
	{
		std::cout << "Error loading red texture ;(" << std::endl;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	int x = 0;





	while ( window.isOpen( ) )
	{
		sf::Event event;
		sprite.setTextureRect(sf::IntRect(0, 0, x, x));

		while ( window.pollEvent( event ) )
		{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
				std:: cout << "Rect + 10" << std::endl;
				x+=10;
				break;


				}
			}


		window.clear();

		window.draw(sprite);

		window.display();
		}
}
