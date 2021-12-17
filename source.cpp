#include <SFML/Graphics.hpp> 
#include <iostream>
#include <time.h>
#include <conio.h>
#include "Graphic.h"
#include "Map.h"
#include <chrono>
#include <future>

//#define W 87

void timer() 
{
	auto start = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_until(start + std::chrono::seconds(1));
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(1025, 1025), "Alisa Studio Works!"); //открываем окно sfml
	Graphic graphic(window); //для вызова функций класса graphic
	Map map; //для вызова функций класса map
	char mMove = 'd';
	auto old = std::chrono::high_resolution_clock::now();
	while (window.isOpen()) // пока окно открыто
	{
		//graphic.SetBackground(sf::Color(15, 15, 15, 255));
		sf::Event event; //показывает действия пользователя
		while (window.pollEvent(event)) //игрок что-то делает
		{
			if (event.type == sf::Event::Closed) //закрывает ли пользователь окно
				window.close(); // закрыть окно
			if (event.type == sf::Event::KeyReleased) //вводим любой символ
			{
				
				if (event.key.code == sf::Keyboard::Key::D)
				{
					mMove = 'd';
					//std::cout << "d" << std::endl;
				}
				else if (event.key.code == sf::Keyboard::Key::S)
				{
					mMove = 's';
					//std::cout << "s" << std::endl;
				}
				else if (event.key.code == sf::Keyboard::Key::A)
				{      
					mMove = 'a';
					//std::cout << "a" << std::endl;
				}
				else if (event.key.code == sf::Keyboard::Key::W)
				{
					mMove = 'w';
					//std::cout << "w" << std::endl;
				}
			}
		}
		if (std::chrono::high_resolution_clock::now() > old + std::chrono::seconds(1)) //прошла одна секунда после последнего движения змейки
		{
			std::cout << mMove << std::endl;
			map.Play(mMove, graphic); //меняем карту
			old = std::chrono::high_resolution_clock::now();
		}

		///window.clear(); //стираем все, что было на экране
		//graphic.SetBackground(sf::Color(15, 15, 15, 255));
	}
}
//добавить функцию dplus в класс smey и использовать в функции hod