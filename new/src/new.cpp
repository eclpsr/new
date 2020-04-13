#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "eclpsr", sf::Style::Titlebar | sf::Style::Close);

	if(!sf::SoundBufferRecorder::isAvailable())
	{
		// error
	}

	sf::SoundBufferRecorder recorder;

	recorder.start();

	recorder.start();
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
					recorder.stop();
					const sf::SoundBuffer &buffer = recorder.getBuffer();

					buffer.saveToFile("src/recording.ogg");
					window.close();

					break;

				}
			}


		window.clear();

		window.draw(background);

		window.display();
		}
}
