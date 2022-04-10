#include "Graphic.h"
#include <iostream>
#include <chrono>
#include <future>
#include <SFML/Graphics.hpp> 
#include "Main.h"


Graphic::Graphic() :
	mWindow(sf::VideoMode(1025, 1025), "Alisa Tun Studio Works!") //��������� ���� sfml
{
};


void Graphic::drawMap(std::vector<std::vector<int>> aCell, std::string aTime) // ������ �����
{
	mWindow.clear(sf::Color(15, 15, 15)); //������ ������ ���

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
			if (aCell[i][j] > 9) rectangle.setFillColor(sf::Color(179, 227, 107)); //���� ������
			if (aCell[i][j] == 1) rectangle.setFillColor(sf::Color(214, 81, 24)); //���� ������
			rectangle.setPosition(j * 104, i * 104);
			mWindow.draw(rectangle);
		}
	}
	sf::RectangleShape timmy; //�������������, �� ������� ����� �����
	timmy.setSize(sf::Vector2f(270, 65)); // ��� �����
	timmy.setOutlineColor(sf::Color(48, 29, 2)); // ���� �������
	timmy.setOutlineThickness(8); // ����� �������
	timmy.setFillColor(sf::Color(255, 160, 122)); // ���� ��������������
	timmy.setPosition(380, 0); // ������� ��������������
	mWindow.draw(timmy); // ������ ���
	sf::Font font;//����� 
	bool b = font.loadFromFile("U:\\Evolution_v2\\Debug\\IndieFlower-Regular.ttf");//�������� ������ ������ ���� ������
	sf::Text text(aTime, font, 65);//������� �����
	text.setFillColor(sf::Color(48, 29, 2));// ���� ������
	text.setPosition(500, -18); // ������� ������
	mWindow.draw(text);
	mWindow.display();
}


int Graphic::whole(char move)
{
	enum Direction {NUN = 0, UP = 'w', RIGHT = 'd', DOWN = 's', LEFT = 'a' };
	while (mWindow.isOpen()) // ���� ���� �������
	{
		//graphic.SetBackground(sf::Color(15, 15, 15, 255));
		sf::Event event; //���������� �������� ������������
		while (mWindow.pollEvent(event)) //����� ���-�� ������
		{
			if (event.type == sf::Event::Closed) //��������� �� ������������ ����
				mWindow.close(); // ������� ����
			if (event.type == sf::Event::KeyReleased) //������ ����� ������
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