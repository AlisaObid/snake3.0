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
	void Move(char aMove); //���� ����
	std::vector<std::vector<int>> getCell();
	double getTime();
	int Size; //����� ������
	enum Direction {NUN = 0, UP = 'w', RIGHT = 'd', DOWN = 's', LEFT = 'a'}; // ������ ��������

private:
	double time;
	std::vector<std::vector<int>> mCell; //������ ����� ������
	int mX, mY; //���������� ������ ������
	int mXe, mYe; // ����� ������
};

#endif 