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
	sf::RenderWindow window(sf::VideoMode(1025, 1025), "Alisa Studio Works!"); //��������� ���� sfml
	Graphic graphic(window); //��� ������ ������� ������ graphic
	Map map; //��� ������ ������� ������ map
	char mMove = 'd';
	auto old = std::chrono::high_resolution_clock::now();
	while (window.isOpen()) // ���� ���� �������
	{
		//graphic.SetBackground(sf::Color(15, 15, 15, 255));
		sf::Event event; //���������� �������� ������������
		while (window.pollEvent(event)) //����� ���-�� ������
		{
			if (event.type == sf::Event::Closed) //��������� �� ������������ ����
				window.close(); // ������� ����
			if (event.type == sf::Event::KeyReleased) //������ ����� ������
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
		if (std::chrono::high_resolution_clock::now() > old + std::chrono::seconds(1)) //������ ���� ������� ����� ���������� �������� ������
		{
			std::cout << mMove << std::endl;
			map.Play(mMove, graphic); //������ �����
			old = std::chrono::high_resolution_clock::now();
		}

		///window.clear(); //������� ���, ��� ���� �� ������
		//graphic.SetBackground(sf::Color(15, 15, 15, 255));
	}
}
//�������� ������� dplus � ����� smey � ������������ � ������� hod