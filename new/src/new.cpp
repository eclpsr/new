#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "eclpsr");

	sf::View view(sf::FloatRect(0, 0, 300, 300));

	window.setView(view);

	/*view.move(sf::Vector2f(50, 100));
	view.move(sf::Vector2f(50, 100));
	view.move(sf::Vector2f(50, 100));*/

	//view.setCenter(sf::Vector2f(300, 300));

	/*view.rotate(25);
	view.rotate(25);
	view.rotate(25);*/

	//view.setRotation(25);
    //view.setRotation(25);

   // view.zoom(2.0);

	view.setSize(sf::Vector2f(1500, 1500));

	window.setView(view);

	sf::Sprite background;

	sf::Texture texture;

	if(!texture.loadFromFile("src/red.png"))
	{
		std::cout<< "ERROR" << std::endl;
	}

	background.setTexture(texture);

	while ( window.isOpen( ) )
	{
		sf::Event event;

		while ( window.pollEvent( event ) ) {

				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;

				}
			}


		window.clear();

		window.draw(background);

		window.display();
		}
}
