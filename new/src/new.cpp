#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "eclpsr");
	sf::Texture texture;
	texture.setRepeated(true); // "разрешить повторять объект"

	if (!texture.loadFromFile("src/red.png"))
	{
		std::cout << "Error loading red texture ;(" << std::endl;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255, 255));
	sprite.scale(sf::Vector2f(0.5, 0.5));
	//sprite.setPosition(sf::Vector2f(300, 200)); // изменить позицию
	//std::cout << sprite.getPosition().x << std::endl;
	//sprite.move(sf::Vector2f(50, 40)); // двигаем объект
	//sprite.setRotation(45); // ротация объекта
	//std::cout << sprite.getRotation() << std::endl;
	//sprite.rotate(15);
	//sprite.setScale(sf::Vector2f(0.7, 0.7)); // Размер объекта
	//std::cout << sprite.getScale().x << std::endl;

	sf::VertexArray lines(sf::LinesStrip, 3);

	lines[0].position = sf::Vector2f(50, 40);
	lines[0].color = sf::Color::Red;

	lines[1].position = sf::Vector2f(300, 50);
	lines[1].color = sf::Color::Magenta;

	lines[2].position = sf::Vector2f(200, 200);
	lines[2].color = sf::Color::Green;

	sf::VertexArray trianglesStrip(sf::TrianglesStrip, 4);

	trianglesStrip[0].position = sf::Vector2f(30, 50);
	trianglesStrip[0].color = sf::Color::Red;

	trianglesStrip[1].position = sf::Vector2f(200, 75);
	trianglesStrip[1].color = sf::Color::Yellow;

	trianglesStrip[2].position = sf::Vector2f(10, 200);
	trianglesStrip[2].color = sf::Color::Magenta;

	trianglesStrip[3].position = sf::Vector2f(500, 500);
	trianglesStrip[3].color = sf::Color::Cyan;

	sf::VertexArray trianglesFan(sf::TrianglesFan, 4);

	trianglesFan[0].position = sf::Vector2f(300, 300);
	trianglesFan[0].color = sf::Color::Red;

	trianglesFan[1].position = sf::Vector2f(300, 50);
	trianglesFan[1].color = sf::Color::Yellow;

	trianglesFan[2].position = sf::Vector2f(450, 250);
	trianglesFan[2].color = sf::Color::Magenta;

	trianglesFan[3].position = sf::Vector2f(350, 400);
	trianglesFan[3].color = sf::Color::Cyan;




	double originX = 0;
	double originY = 0;
	while ( window.isOpen( ) )
	{
		sf::Event event;

		sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x * originX, sprite.getTexture()->getSize().y * originY)); // двигает объект


		while ( window.pollEvent( event ) ) {

				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
						case sf::Keyboard::W:
							originY += 0.05;
							break;
						case sf::Keyboard::A:
							originX += 0.05;
							break;
						case sf::Keyboard::S:
							originY -= 0.05;
							break;
						case sf::Keyboard::D:
							originX -= 0.05;
							break;
					}
				break;

				}
			}


		window.clear();

		window.draw(trianglesFan);

		window.draw(sprite);

		window.display();
		}
}
