#include "Map.h"


Map::Map()
{
	Map::mCell.resize(10, std::vector<int>(10, 0)); //������ ����� ������
	mCell[1][1] = 10; // ������ ������ ������ ��� ������
	//�������� ������ ��� ������� ������ ��������
	std::srand(std::time(nullptr));
	int mRandAppleI = std::rand() % 10;
	mCell[2][mRandAppleI] = 1;
	mX = 1;
	time = 1;
	mY = 1;
	mYe = 1;
	mXe = 1;
	Size = 1;
};


void Map::Move(char aMove)
{
	if (aMove == RIGHT) mCell[mY][mX] = 21; //���� ���� ������ 1
	if (aMove == DOWN)  mCell[mY][mX] = 22; //���� ���� ������ 2
	if (aMove == LEFT)  mCell[mY][mX] = 23; //���� ���� ������ 3
	if (aMove == UP)    mCell[mY][mX] = 20; //���� ���� ������ 4
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
		(mCell[mY + a][mX + b] > 9 && mCell[mY + a][mX + b] < 24))
	{
		while (true)
		{
			std::cout << "ho"; // ��������
		}
	}
	if (mCell[mY + a][mX + b] == 1) // ���� �� ����� ������
	{
		EatApple = true; // �� ������ �������
		int apple1 = rand() % 10, apple2 = rand() % 10; // ��������� ���������� ������ ������
		while (mCell[apple1][apple2] > 9 && mCell[apple1][apple2] < 24)
		{
			apple1 = rand() % 10;
			apple2 = rand() % 10;
		}
		Size++;
		mCell[apple1][apple2] = 1; // ������ ����� ������
		if (time < 5) time += 0.2;
	}
	mCell[mY + a][mX + b] = mCell[mY][mX]; // ������ �������������
	if (Size > 1) mCell[mY][mX] -= 10;
	mX += b;
	mY += a;
	if (!EatApple) //���� �� ����� ������, �� ����� �������� �����
	{
		int i = 0, j = 0; //���� ���� �����
		if (mCell[mYe][mXe] % 10 == 1) j++; //���� ���� ����� 1
		if (mCell[mYe][mXe] % 10 == 2) i++; //���� ���� ����� 2
		if (mCell[mYe][mXe] % 10 == 3) j--; //���� ���� ����� 3
		if (mCell[mYe][mXe] % 10 == 0) i--; //���� ���� ����� 4
		mCell[mYe][mXe] = 0; // �� ����� ������� ������ ������ ������ ������
		mYe += i; //������ ���������� ������
		mXe += j;
	}
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
