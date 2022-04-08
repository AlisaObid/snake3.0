#include "Graphic.h"
#include "Map.h"
#include "Main.h"


void Main::run()
{
	Graphic graphic;
	Map map;
	sf::Clock clock; //��� ��������
	float curTime = clock.getElapsedTime().asMilliseconds(); // ��� ����
	char move = Map::Direction::RIGHT; // ������� ����� ����� ���� �������
	while (true)
	{
		graphic.drawMap(map.getCell()); //������ ����� �������� �����
		move = graphic.whole(move); // ������� �� �������� ������
		curTime = clock.getElapsedTime().asMilliseconds(); // ��� ��������
		if (curTime > 1000 / map.getTime()) // ������ ���� �������
		{
			map.Move(move); // ������� ������
			clock.restart();
		}
	}
	

}