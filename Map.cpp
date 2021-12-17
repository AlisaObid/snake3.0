#include "Map.h"


Map::Map() :
	mCell(10, std::vector<int>(10, 0)) //номера €чеек змейки
{
	mCell[1][1] = 1; // ставим первую €чейку дл€ змейки
	//создание €чейки дл€ первого €блока рандомом
	int mRandAppleI = rand() % 10;
	mCell[1][2] = 101;
	mX = 1;
	mY = 1;
	mSize= 0;
}


void Map::Play(char aMove, Graphic& graphic)	//сама игра
{
	//не выходит ли звейка за границы карты
	if (((aMove == 'a' && (mX - 1 < 0 || (mCell[mY][mX - 1] > 0 && mCell[mY][mX - 1] < 101))) || 
		 (aMove == 's' && (mY + 1 > 9 || (mCell[mY + 1][mX] > 0 && mCell[mY + 1][mX] < 101))) ||
		 (aMove == 'd' && (mX + 1 > 9 || (mCell[mY][mX + 1] > 0 && mCell[mY][mX + 1] < 101))) ||
		 (aMove == 'w' && (mY - 1 < 0 || (mCell[mY - 1][mX] > 0 && mCell[mY - 1][mX] < 101)))))
	{
		// :(
		std::cout << mY << ' ' << mX;
		graphic.DrawText("Game Over. Your name's \"lox\" :(", 10, 10, sf::Color(255, 255, 255));
		while (true)
		{
			std::cout << "lox";
		}
	}
	//змейка ходит
	if (aMove == 'a')
	{
		mX--;
	}
	else if (aMove == 's')
	{
		mY++;
	}
	else if (aMove == 'd')
	{
		mX++;
	}
	else if (aMove == 'w')
	{
		mY--;
	}
	//съела ли змейка €блоко
	bool aEatApple = 0;
	if (mCell[mY][mX] == 101)
	{
		aEatApple = 1;
		//змейка растет
		mSize++; // d++
	}
	//голова змейки ходит
	mCell[mY][mX] = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << mCell[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	int mNext = 1; //на какой €чейке змейки находитс€ след цикл
	//удал€ем €чейку с хвостом (у нее максимальный номер) и мен€ем номера, если змейка не съела €блоко
	int aI = mY, aJ = mX; //где мы находимс€
	for (int i = 0; i < mSize; i++)
	{
		std::cout << mNext << std::endl;
		//ищем предыдущую €чейку змейки (ее номер равен mNext)
		if (aI > 0 && mCell[aI - 1][aJ] == mNext)
		{
			mNext++; //следующа€ €чейка на 1 больше
			aI--; //мен€ем позицию €чейки на которой мы находимс€
			mCell[aI][aJ]++; //увеличиваем номер €чейки на которой мы находимс€
			std::cout << '+' << std::endl;
			if (mCell[aI][aJ] >= mSize) //мы на последней €чейке змейки?
			{
				if (aEatApple == 0) // если змейка съела €блоко, то ее нельз€ уменьшать
				{
					mCell[aI][aJ] = 0;
				}
				break;
			}
			continue;
		}
		if (aJ > 0 && mCell[aI][aJ - 1] == mNext)
		{
			mNext++;
			aJ--;
			mCell[aI][aJ]++;
			std::cout << '+' << std::endl;
			if (mCell[aI][aJ] >= mSize)
			{
				if (aEatApple == 0)
				{
					mCell[aI][aJ] = 0;
				}
				break;
			}
			continue;
		}
		if (aI < 9 && mCell[aI + 1][aJ] == mNext)
		{
			mNext++;
			aI++;
			mCell[aI][aJ]++;
			std::cout << '+' << std::endl;
			if (mCell[aI][aJ] >= mSize)
			{
				if (aEatApple == 0)
				{
					mCell[aI][aJ] = 0;
				}
				break;
			}
			continue;
		}
		if (aJ < 9 && mCell[aI][aJ + 1] == mNext)
		{
			mNext++;
			aJ++;
			mCell[aI][aJ]++;
			std::cout << '+' << std::endl;
			if (mCell[aI][aJ] >= mSize)
			{
				if (aEatApple == 0)
				{
					mCell[aI][aJ] = 0;
				}
				break;
			}
			continue;
		}
	}
	//создаем новое €блоко
	if (aEatApple) //создавать €блоко можно только тогда, когда змей съел предыдущее
	{
		int mRandI = rand() % 10, mRandJ = rand() % 10; // рандомный номер дл€ €блока
		while (mCell[mRandI][mRandJ] > 0) // €блоко нельз€ создавать в змейке
		{
			mRandI = rand() % 10; // мен€ем координаты €блока
			mRandJ = rand() % 10;
		}
		mCell[mRandI][mRandJ] = 101; // ставим €блоко
	}
	graphic.DrawMap(mCell);//вывод карты
}
