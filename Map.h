#ifndef MAP_H
#define MAP_H

#include <ctime>

#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp> 


class Map
{
public:
	Map();
	~Map();
	void Move(char aMove); //сама игра
	std::vector<std::vector<int>> getCell();
	double getTime();
	int Size; //длина змейки
	enum Direction {NUN = 0, UP = 'w', RIGHT = 'd', DOWN = 's', LEFT = 'a'}; // делаем неудобно

private:
	double time;
	std::vector<std::vector<int>> mCell; //номера €чеек змейки
	int mX, mY; //координаты головы змейки
	int mXe, mYe; // хвост змейки
};

#endif 