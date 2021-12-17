#include "Map.h"


Map::Map() :
	mCell(10, std::vector<int>(10, 0)) //������ ����� ������
{
	mCell[1][1] = 1; // ������ ������ ������ ��� ������
	//�������� ������ ��� ������� ������ ��������
	int mRandAppleI = rand() % 10;
	mCell[1][2] = 101;
	mX = 1;
	mY = 1;
	mSize= 0;
}


void Map::Play(char aMove, Graphic& graphic)	//���� ����
{
	//�� ������� �� ������ �� ������� �����
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
	//������ �����
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
	//����� �� ������ ������
	bool aEatApple = 0;
	if (mCell[mY][mX] == 101)
	{
		aEatApple = 1;
		//������ ������
		mSize++; // d++
	}
	//������ ������ �����
	mCell[mY][mX] = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << mCell[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	int mNext = 1; //�� ����� ������ ������ ��������� ���� ����
	//������� ������ � ������� (� ��� ������������ �����) � ������ ������, ���� ������ �� ����� ������
	int aI = mY, aJ = mX; //��� �� ���������
	for (int i = 0; i < mSize; i++)
	{
		std::cout << mNext << std::endl;
		//���� ���������� ������ ������ (�� ����� ����� mNext)
		if (aI > 0 && mCell[aI - 1][aJ] == mNext)
		{
			mNext++; //��������� ������ �� 1 ������
			aI--; //������ ������� ������ �� ������� �� ���������
			mCell[aI][aJ]++; //����������� ����� ������ �� ������� �� ���������
			std::cout << '+' << std::endl;
			if (mCell[aI][aJ] >= mSize) //�� �� ��������� ������ ������?
			{
				if (aEatApple == 0) // ���� ������ ����� ������, �� �� ������ ���������
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
	//������� ����� ������
	if (aEatApple) //��������� ������ ����� ������ �����, ����� ���� ���� ����������
	{
		int mRandI = rand() % 10, mRandJ = rand() % 10; // ��������� ����� ��� ������
		while (mCell[mRandI][mRandJ] > 0) // ������ ������ ��������� � ������
		{
			mRandI = rand() % 10; // ������ ���������� ������
			mRandJ = rand() % 10;
		}
		mCell[mRandI][mRandJ] = 101; // ������ ������
	}
	graphic.DrawMap(mCell);//����� �����
}
