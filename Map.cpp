#include "Map.h"


Map::Map()
{
	Map::mCell.resize(10, std::vector<int>(10, 0)); //������ ����� ������
	mCell[1][1] = 10; // ������ ������ ������ ��� ������
	//�������� ������ ��� ������� ������ ��������
	int mRandAppleI = rand() % 10;
	mCell[2][mRandAppleI] = 1;
	mX = 1;
	time = 1;
	mY = 1;
	mYe = 1;
	mXe = 1;
	mSize = 0;
};


void Map::Move(char aMove)
{
	if (aMove == RIGHT) mCell[mY][mX] = 11; //���� ���� ������ 1
	if (aMove == DOWN) mCell[mY][mX] = 12; //���� ���� ������ 2
	if (aMove == LEFT) mCell[mY][mX] = 13; //���� ���� ������ 3
	if (aMove == UP) mCell[mY][mX] = 10; //���� ���� ������ 4
	int a = 0, b = 0; // a ��� i, b ��� j
	bool EatApple = 0;
	if (aMove == RIGHT) // ���� ������ ���� ������
	{
		b++; // ����� j ����������� �� 1
	}
	if (aMove == DOWN) 
	{
		a++;
	}
	if (aMove == LEFT)
	{
		b--;
	}
	if (aMove == UP)
	{
		a--;
	}
	if (mX + b > 9 || mX + b < 0 ||
		mY + a > 9 || mY + a < 0 ||
		(mCell[mY + a][mX + b] > 9 && mCell[mY + a][mX + b] < 14))
	{
		while (true)
		{
			std::cout << '.'; // ��������
		}
	}
	if (mCell[mY + a][mX + b] == 1) // ���� �� ����� ������
	{
		EatApple = 1; // �� ������ �������
		int apple1 = rand() % 10, apple2 = rand() % 10; // ��������� ���������� ������ ������
		while (mCell[apple1][apple2] > 9 && mCell[apple1][apple2] < 14)
		{
			apple1 = rand() % 10;
			apple2 = rand() % 10;
		}
		mCell[apple1][apple2] = 1; // ������ ����� ������
		if (time < 5) time += 0.2;
	}
	mCell[mY + a][mX + b] = mCell[mY][mX]; // ������ �������������
	mX += b;
	mY += a;
	if (!EatApple) //���� �� ����� ������, �� ����� �������� �����
	{
		int i = 0, j = 0; //���� ���� �����
		if (mCell[mYe][mXe] == 11) j++; //���� ���� ����� 1
		if (mCell[mYe][mXe] == 12) i++; //���� ���� ����� 2
		if (mCell[mYe][mXe] == 13) j--; //���� ���� ����� 3
		if (mCell[mYe][mXe] == 10) i--; //���� ���� ����� 4
		mCell[mYe][mXe] = 0; // �� ����� ������� ������ ������ ������ ������
		mYe += i; //������ ���������� ������
		mXe += j;
	}
	//Graphic.drawMap(mCell, aWindow);
}


std::vector<std::vector<int>> Map::getCell()
{
	return mCell;
}


double Map::getTime()
{
	return time;
}


Map::~Map() {};
