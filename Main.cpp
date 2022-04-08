#include "Graphic.h"
#include "Map.h"
#include "Main.h"


void Main::run()
{
	Graphic graphic;
	Map map;
	sf::Clock clock; //для тайминга
	float curTime = clock.getElapsedTime().asMilliseconds(); // это тоже
	char move = Map::Direction::RIGHT; // сначала игрок будет идти направо
	while (true)
	{
		graphic.drawMap(map.getCell()); //всегда будем рисовать карту
		move = graphic.whole(move); // смотрим на действия игрока
		curTime = clock.getElapsedTime().asMilliseconds(); // для тайминга
		if (curTime > 1000 / map.getTime()) // прошла одна секунда
		{
			map.Move(move); // двигаем змейку
			clock.restart();
		}
	}
	

}