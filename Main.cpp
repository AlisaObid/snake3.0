#include "Graphic.h"
#include "Map.h"
#include "Main.h"
#include <string>


void Main::run()
{
	Graphic graphic;
	Map map;
	int time = 0; 
	sf::Clock clock; //��� ��������
	sf::Clock clock2; //��� ��������
	float curTime = clock.getElapsedTime().asMilliseconds(); // ��� ����
	float curTime2 = clock2.getElapsedTime().asMilliseconds();
	char move = Map::Direction::RIGHT; // ������� ����� ����� ���� �������
	while (true)
	{
		std::string strTime = std::to_string(time);
		graphic.drawMap(map.getCell(), strTime); //������ ����� �������� �����
		move = graphic.whole(move); // ������� �� �������� ������
		curTime = clock.getElapsedTime().asMilliseconds(); // ��� ��������
		curTime2 = clock2.getElapsedTime().asMilliseconds(); // ��� ��������
		if (curTime2 > 1000) // ������ ���� �������
		{
			time++; 
			clock2.restart();
		}
		if (curTime > 1000 / map.getTime()) // ������ ����� �����������
		{
			map.Move(move); // ������� ������
			clock.restart();
		}
	}
	

}