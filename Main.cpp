#include "Graphic.h"
#include "Map.h"
#include "Main.h"
#include <string>


void Main::run()
{
	Graphic graphic;
	Map map;
	int time = 0; 
	sf::Clock clock; //для тайминга
	sf::Clock clock2; //для тайминга
	bool menu = 0;
	float curTime = clock.getElapsedTime().asMilliseconds(); // это тоже
	float curTime2 = clock2.getElapsedTime().asMilliseconds();
	char move = Map::Direction::RIGHT; // сначала игрок будет идти направо
	while (true)
	{
		if (map.Size == 10)
		{
			map.changeLVL();
		}

		std::string strTime = std::to_string(time);
		std::string strSize = std::to_string(map.Size);
		graphic.drawMap(map.getCell(), strTime, strSize); //всегда будем рисовать карту
		move = graphic.whole(move); // смотрим на действия игрока
		if (!graphic.start) continue;
		curTime = clock.getElapsedTime().asMilliseconds(); // для тайминга
		curTime2 = clock2.getElapsedTime().asMilliseconds(); // для тайминга
		if (curTime2 > 1000) // прошла одна секунда
		{
			time++; 
			clock2.restart();
		}
		if (curTime > 800 / map.getTime()) // змейке нужно подвинуться
		{
			map.Move(move); // двигаем змейку
			clock.restart();
		}
	}
	

}