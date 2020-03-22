#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "eclpsr");

	//sf::RectangleShape rectangle(sf::Vector2f(200, 40)) // Прямоугольник
	//rectangle.setSize(sf::Vector2f(400, 67));
	//sf::CircleShape circle(150); // Круг
	//sf::CircleShape polygon(300, 3); // Треугольник
	//sf::CircleShape polygon(300, 4); // Квадрат(Ромб)
	//sf::CircleShape polygon(300, 6); // Шестиугольник
	/*sf::RectangleShape line;
	line.setSize(sf::Vector2f(200, 3));
	sf::Vertex line2[] =
	{
			sf::Vertex(sf::Vector2f(25, 10)),
			sf::Vertex(sf::Vector2f(400, 100))
	};*/

	sf::CircleShape circle(150);
	circle.setRadius(200);
	circle.setPointCount(300);
	//circle.setFillColor(sf::Color::Cyan);
	//circle.setFillColor(sf::Color(255, 155, 155));
	//circle.setOutlineColor(sf::Color::Blue);
	//circle.setOutlineThickness(-10);
	sf::Texture circletexture;
	if(!circletexture.loadFromFile("src/paper.jpg"))
	{
		std::cout << "ERROR ERROR ERROR" << std::endl;
	}
	circle.setTexture(&circletexture);
	circle.setTextureRect(sf::IntRect(0, 0, 1500, 1500));

	sf::Vertex point;
	point.position = sf::Vector2f(300, 300);
	point.color = sf::Color::Red;
	sf::VertexArray line(sf::Lines, 2);

	line[0].position = sf::Vector2f(200, 150);
	line[0].color = sf::Color::Red;

//	line[1].position = sf::Vector2f(400, 90);0
//	line[1].color = sf::Color::Green;

	line[1] = point;

	sf::VertexArray triangle(sf::Triangles, 3);
	triangle[0].position = sf::Vector2f(20, 50);
	triangle[0].color = sf::Color::White;

	triangle[1].position = sf::Vector2f(70, 250);
	triangle[1].color = sf::Color::Red;

	triangle[2].position = sf::Vector2f(10, 250);
	triangle[2].color = sf::Color::Blue;

	sf::VertexArray quad(sf::Quads, 4);

	quad[0].position = sf::Vector2f(40, 50);
	quad[0].color = sf::Color::Yellow;

	quad[1].position = sf::Vector2f(80, 50);
	quad[1].color = sf::Color::Red;

	quad[2].position = sf::Vector2f(90, 200);
	quad[2].color = sf::Color::Green;

	quad[3].position = sf::Vector2f(10, 150);
	quad[3].color = sf::Color::Cyan;


	sf::Texture texture;
	texture.setRepeated(true); // "разрешить повторять объект"

	if (!texture.loadFromFile("src/red.png"))
	{
		std::cout << "Error loading red texture ;(" << std::endl;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255, 255));
	//sprite.setPosition(sf::Vector2f(300, 200)); // изменить позицию
	//std::cout << sprite.getPosition().x << std::endl;
	//sprite.move(sf::Vector2f(50, 40)); // двигаем объект
	//sprite.setRotation(45); // ротация объекта
	//std::cout << sprite.getRotation() << std::endl;
	//sprite.rotate(15);
	//sprite.setScale(sf::Vector2f(0.7, 0.7)); // Размер объекта
	//std::cout << sprite.getScale().x << std::endl;
	sprite.scale(sf::Vector2f(0.5, 0.5));




	double originX = 0;
	double originY = 0;
	while ( window.isOpen( ) )
	{
		sf::Event event;
		//int x = 0;
		//sprite.setTextureRect(sf::IntRect(0, 0, x, x)); // "видимость объекта"

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



		window.draw(circle);

		window.draw(triangle);

		window.draw(quad);

		window.draw(sprite);

		window.display();
		}
}
