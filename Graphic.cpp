#include "Graphic.h"
#include <iostream>
#include <chrono>
#include <future>
#include <SFML/Graphics.hpp> 
#include "Main.h"


Graphic::Graphic() :
	mWindow(sf::VideoMode(1025, 1025), "Alisa Tun Studio Works!") //открываем окно sfml
{
};


void Graphic::drawMap(std::vector<std::vector<int>> aCell) // рисуем карту
{
	mWindow.clear(sf::Color(15, 15, 15)); //делаем черный фон

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(104, 104));
	rectangle.setOutlineColor(sf::Color(0, 0, 0));
	rectangle.setOutlineThickness(5);

	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if ((i + j) % 2)
			{
				rectangle.setFillColor(sf::Color(50, 50, 50));
			}
			else
			{
				rectangle.setFillColor(sf::Color(0, 0, 0));
			}
			if (aCell[i][j] > 9) rectangle.setFillColor(sf::Color(36, 240, 128));
			if (aCell[i][j] == 1) rectangle.setFillColor(sf::Color(200, 99, 99));
			rectangle.setPosition(j * 104, i * 104);
			mWindow.draw(rectangle);
		}
	}
	mWindow.display();
}


int Graphic::whole(char move)
{
	enum Direction {NUN = 0, UP = 'w', RIGHT = 'd', DOWN = 's', LEFT = 'a' };
	while (mWindow.isOpen()) // пока окно открыто
	{
		//graphic.SetBackground(sf::Color(15, 15, 15, 255));
		sf::Event event; //показывает действия пользователя
		while (mWindow.pollEvent(event)) //игрок что-то делает
		{
			if (event.type == sf::Event::Closed) //закрывает ли пользователь окно
				mWindow.close(); // закрыть окно
			if (event.type == sf::Event::KeyReleased) //вводим любой символ
			{
				
				if (event.key.code == sf::Keyboard::Key::D)
				{
					move = RIGHT;
					//std::cout << "d" << std::endl;
				}
				else if (event.key.code == sf::Keyboard::Key::S)
				{
					move = DOWN;
					//std::cout << "s" << std::endl;
				}
				else if (event.key.code == sf::Keyboard::Key::A)
				{      
					move = LEFT;
					//std::cout << "a" << std::endl;
				}
				else if (event.key.code == sf::Keyboard::Key::W)
				{
					move = UP;
					//std::cout << "w" << std::endl;
				}
			}
		} 
		return move;
	}
}