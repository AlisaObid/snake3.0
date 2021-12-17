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
	void Play(char aMove, Graphic& graphic); //сама игра
private:
	std::vector<std::vector<int>> mCell; //номера €чеек змейки
	int mX, mY; //координаты головы змейки
	int mSize; //длина змейки
};

#endif 