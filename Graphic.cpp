#include "Graphic.h"

Graphic::Graphic(sf::RenderWindow& aWindow) :
	mWindow(aWindow)
{
	mFont.loadFromFile("U:\\Evolution_v2\\font.ttf"); //���� �� ����� �� �������
	mText.setFont(mFont);
	mText.setCharacterSize(40);
}

//�������� �����
void Graphic::DrawText(std::string aString,   
	std::int16_t x, std::int16_t y, sf::Color aColor) //���������� �����
{
	mText.setPosition(sf::Vector2f(y, x)); //��� ��������� �����
	mText.setFillColor(aColor);//��������� �����
	mText.setString(aString); //������� �����
	mWindow.draw(mText); //�������� ���
}


void Graphic::SetBackground(sf::Color aColor) //���
{
	//mWindow.clear(aColor);
}


void Graphic::DrawMap(std::vector<std::vector<int>> aMap) //���������� �����
{
	mWindow.clear();
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			sf::RectangleShape rectangle;
			if (aMap[i][j] == 0)
			{
				rectangle.setFillColor(sf::Color(15, 15, 15)); //���� ���������
			}
			if (aMap[i][j] > 0 && aMap[i][j] < 101)
			{
				rectangle.setFillColor(sf::Color(84, 255, 159)); //���� ���������
			}
			if (aMap[i][j] == 101)
			{
				rectangle.setFillColor(sf::Color(155, 17, 30)); //���� ���������
			}
			rectangle.setSize(sf::Vector2f(70, 70)); //������ ���������
			rectangle.setPosition(105 * j, 105 * i); //������� ���������
			mWindow.draw(rectangle); //������ �������
		}
		std::cout << std::endl;
	}
	mWindow.display();
}

