#include <iostream>
#include <chrono>
#include <future>
#include <SFML/Graphics.hpp> 
#include "Main.h"


//#define W 87

//enum Cell { up = 10, down = 11, left = 12, right = 13, apple = 1, empt = 0}; // направления змейки, яблоко, пустые



int main()
{
	//sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "");
	//sf::RectangleShape shape(sf::Vector2f(100.F, 100.F));
	//sf::Texture texture;
	//shape.setFillColor(sf::Color::Red);
	//texture.loadFromFile("../cake.png");
	//shape.setTexture(&texture);

	//while (window.isOpen())
	//{
	//	static sf::Event event{};
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::EventType::Closed)
	//		{
	//			window.close();
	//		}
	//	}

	//	window.clear();
	//	window.draw(shape);
	//	window.display();
	//}
	

	Main Main;
	Main.run();
}