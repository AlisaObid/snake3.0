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
	void Move(char aMove); //���� ����
	std::vector<std::vector<int>> getCell();
	double getTime();
	enum Direction {NUN = 0, UP = 'w', RIGHT = 'd', DOWN = 's', LEFT = 'a'}; // ������ ��������

private:
	double time;
	std::vector<std::vector<int>> mCell; //������ ����� ������
	int mX, mY; //���������� ������ ������
	int mXe, mYe; // ����� ������
	int mSize; //����� ������
};

#endif 