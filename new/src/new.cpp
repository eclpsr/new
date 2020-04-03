#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "eclpsr");

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("src/sound.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}

	sf::Sound sound2;

	sound2.setBuffer(buffer);

	sound2.play();


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

	// view.setSize(sf::Vector2f(1500, 1500));


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

				case sf::Event::Resized:
					sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
					window.setView(sf::View(visibleArea));

					break;

				}
			}


		window.clear();

		window.draw(background);

		window.display();
		}
}
