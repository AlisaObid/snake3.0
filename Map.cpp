#include "Map.h"


Map::Map()
{
	Map::mCell.resize(10, std::vector<int>(10, 0)); //������ ����� ������
	Map::LVLs = { //�������� �������
		{1, 4, 2, 4, 3, 4, 4, 4, 5, 1, 6, 1, 7, 1, 7, 5, 7, 6, 7, 7, 7, 8},
		{5, 1, 5, 8, 5, 2, 5, 3, 5, 4, 5, 5, 5, 6, 5, 7, 1, 8, 2, 8, 7, 8, 8, 8},
		{5, 1, 5, 8, 5, 2, 5, 3, 5, 4, 5, 5, 5, 6, 5, 7, 1, 8, 2, 8, 7, 8, 8, 8,
		 1, 5, 8, 5, 2, 5, 3, 5, 4, 5, 5, 5, 6, 5, 7, 5, 8, 1, 8, 2},
		{4, 1, 4, 2, 4, 3, 4, 4, 4, 5, 4, 6, 4, 7, 4, 8, 4, 9, 1, 7, 1, 8, 8, 2, 8, 3, 1, 2, 2, 2,
		 8, 7, 8, 8, 6, 0, 6, 1, 6, 2, 6, 3, 6, 4, 6, 5, 6, 6, 6, 7, 6, 8} };
	mCell[1][1] = 10; // ������ ������ ������ ��� ������
	//�������� ������ ��� ������� ������ ��������
	std::srand(std::time(nullptr));
	LVL = -1;
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
		(mCell[mY + a][mX + b] > 9 && mCell[mY + a][mX + b] < 24)
		||mCell[mY + a][mX + b] == 44)
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
		while (mCell[apple1][apple2] > 9 && mCell[apple1][apple2] < 45)
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


void Map::changeLVL()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) mCell[i][j] = 0;
	}
	LVL++; // ������ �������
	if (LVL == 4) //����� ������ ��� ������
	{
		while (true)
		{
			std::cout << "Win! Thanks for game!";
		}
	}


	int y; // ��� ��������� ����� ����
	for (int i = 0; i < LVLs[LVL].size(); i++)
	{
		if (i % 2 == 0) y = LVLs[LVL][i];
		else
		{
			mCell[y][LVLs[LVL][i]] = 44;
		}
	}


	std::srand(std::time(nullptr));
	mCell[1][1] = 10; // ������ ������ ������ ��� ������
	int apple1 = rand() % 10, apple2 = rand() % 10; // ��������� ���������� ������ ������
	while (mCell[apple1][apple2] > 9 && mCell[apple1][apple2] < 45)
	{
		apple1 = rand() % 10;
		apple2 = rand() % 10;
	}


	Size = 1;
	mCell[apple1][apple2] = 1; // ������ ����� ������
	mX = 1;
	time = 1;
	mY = 1;
	mYe = 1;
	mXe = 1;
	Size = 1;
}


double Map::getTime()
{
	return time;
}


Map::~Map() {};
