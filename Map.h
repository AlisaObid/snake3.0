#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp> 
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Graphic.h"

class Map
{
public:
	Map();
	~Map();
	void Move(char aMove); //сама игра
	std::vector<std::vector<int>> getCell();
	double getTime();
	enum Direction {NUN = 0, UP = 'w', RIGHT = 'd', DOWN = 's', LEFT = 'a'}; // делаем неудобно

private:
	double time;
	std::vector<std::vector<int>> mCell; //номера €чеек змейки
	int mX, mY; //координаты головы змейки
	int mXe, mYe; // хвост змейки
	int mSize; //длина змейки
};

#endif 