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


void Graphic::drawMap(std::vector<std::vector<int>> aCell, std::string aTime) // рисуем карту
{
	mWindow.clear(sf::Color(15, 15, 15)); //делаем черный фон

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(104, 104));
	rectangle.setOutlineColor(sf::Color(48, 29, 2));
	rectangle.setOutlineThickness(5);

	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if ((i + j) % 2)
			{
				rectangle.setFillColor(sf::Color(255, 228, 196));
			}
			else
			{
				rectangle.setFillColor(sf::Color(205, 133, 63)); 
			}
			if (aCell[i][j] > 9) rectangle.setFillColor(sf::Color(179, 227, 107)); //цвет змейки
			if (aCell[i][j] == 1) rectangle.setFillColor(sf::Color(214, 81, 24)); //цвет яблока
			rectangle.setPosition(j * 104, i * 104);
			mWindow.draw(rectangle);
		}
	}
	sf::RectangleShape timmy; //Прямоугольник, на котором будет время
	timmy.setSize(sf::Vector2f(270, 65)); // его длина
	timmy.setOutlineColor(sf::Color(48, 29, 2)); // цвет контура
	timmy.setOutlineThickness(8); // длина контура
	timmy.setFillColor(sf::Color(255, 160, 122)); // цвет прямоугольника
	timmy.setPosition(380, 0); // позиция прямоугольника
	mWindow.draw(timmy); // рисуем его
	sf::Font font;//шрифт 
	bool b = font.loadFromFile("U:\\Evolution_v2\\Debug\\IndieFlower-Regular.ttf");//передаем нашему шрифту файл шрифта
	sf::Text text(aTime, font, 65);//создаем текст
	text.setFillColor(sf::Color(48, 29, 2));// цвет текста
	text.setPosition(500, -18); // позиция текста
	mWindow.draw(text);
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