#include "Map.h"


Map::Map()
{
	Map::mCell.resize(10, std::vector<int>(10, 0)); //номера €чеек змейки
	mCell[1][1] = 10; // ставим первую €чейку дл€ змейки
	//создание €чейки дл€ первого €блока рандомом
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
	if (aMove == RIGHT) mCell[mY][mX] = 11; //куда идет голова 1
	if (aMove == DOWN) mCell[mY][mX] = 12; //куда идет голова 2
	if (aMove == LEFT) mCell[mY][mX] = 13; //куда идет голова 3
	if (aMove == UP) mCell[mY][mX] = 10; //куда идет голова 4
	int a = 0, b = 0; // a дл€ i, b дл€ j
	bool EatApple = 0;
	if (aMove == RIGHT) // если змейка идет вправо
	{
		b++; // нужно j увеличивать на 1
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
			std::cout << '.'; // проигрыш
		}
	}
	if (mCell[mY + a][mX + b] == 1) // если мы съели €блоко
	{
		EatApple = 1; // то €блоко съедено
		int apple1 = rand() % 10, apple2 = rand() % 10; // подбираем координаты нового €блока
		while (mCell[apple1][apple2] > 9 && mCell[apple1][apple2] < 14)
		{
			apple1 = rand() % 10;
			apple2 = rand() % 10;
		}
		mCell[apple1][apple2] = 1; // ставим новое €блоко
		if (time < 5) time += 0.2;
	}
	mCell[mY + a][mX + b] = mCell[mY][mX]; // голова передвинулась
	mX += b;
	mY += a;
	if (!EatApple) //если не съели €блоко, то нужно обрезать хвост
	{
		int i = 0, j = 0; //куда идет хвост
		if (mCell[mYe][mXe] == 11) j++; //куда идет хвост 1
		if (mCell[mYe][mXe] == 12) i++; //куда идет хвост 2
		if (mCell[mYe][mXe] == 13) j--; //куда идет хвост 3
		if (mCell[mYe][mXe] == 10) i--; //куда идет хвост 4
		mCell[mYe][mXe] = 0; // на месте старого хвоста теперь пуста€ €чейка
		mYe += i; //мен€ем координаты хвоста
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
