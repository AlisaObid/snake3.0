#include "Graphic.h"
#include <iostream>
#include <chrono>
#include <future>
#include "Button.h"
#include <SFML/Graphics.hpp> 
#include "Main.h"


#define RECT_SITE_SIZE 98.F

Graphic::Graphic() :
	mWindow(sf::VideoMode(1025, 1025), "Alisa Tun Studio Works!") //открываем окно sfml
{

	isLoadedWhite = textureWhite.loadFromFile("../cakewhite.png");// загружаем картинку
	spriteWhite.setTexture(textureWhite); // она будет вместо €блока
	spriteWhite.setScale(RECT_SITE_SIZE / spriteWhite.getGlobalBounds().width,
		RECT_SITE_SIZE / spriteWhite.getGlobalBounds().height);

	isLoadedBlack = textureBlack.loadFromFile("../cakeblack.png");// загружаем картинку
	spriteBlack.setTexture(textureBlack); // она будет вместо €блока
	spriteBlack.setScale(RECT_SITE_SIZE / spriteBlack.getGlobalBounds().width,
		RECT_SITE_SIZE / spriteBlack.getGlobalBounds().height);

	color.resize(5, std::vector<int>(3));

	color[0][0] = 179;
	color[0][1] = 227;
	color[0][2] = 107;

	color[1][0] = 243;
	color[1][1] = 135;
	color[1][2] = 121;

	color[2][0] = 151;
	color[2][1] = 164;
	color[2][2] = 225;

	color[3][0] = 165;
	color[3][1] = 228;
	color[3][2] = 210;

	color[4][0] = 244;
	color[4][1] = 218;
	color[4][2] = 131;

	std::srand(std::time(nullptr));
	RandColor1 = std::rand() % 5;
	int RandColor2 = std::rand() % 3;
	std::cout << RandColor2;
	if (RandColor2 != 1) RandColor1 = 0;
};


void Graphic::timmychinka(std::string aTime, int x, int y, int sizex, int sizey)
{
	sf::RectangleShape timmy; //ѕр€моугольник, на котором будет врем€
	timmy.setSize(sf::Vector2f(sizex, sizey)); // его длина
	timmy.setOutlineColor(sf::Color(48, 29, 2)); // цвет контура
	timmy.setOutlineThickness(8); // длина контура
	timmy.setFillColor(sf::Color(255, 160, 122)); // цвет пр€моугольника
	timmy.setPosition(x, y); // позици€ пр€моугольника
	mWindow.draw(timmy); // рисуем его
	sf::Font font;//шрифт 
	bool b = font.loadFromFile("U:\\Evolution_v2\\Debug\\IndieFlower-Regular.ttf");//передаем нашему шрифту файл шрифта
	sf::Text text(aTime, font, 65);//создаем текст
	text.setFillColor(sf::Color(48, 29, 2));// цвет текста
	text.setPosition(x + 100, y + 15); // позици€ текста
	mWindow.draw(text);
}


void Graphic::drawMap(std::vector<std::vector<int>> aCell, std::string aTime) // рисуем карту
{
	if (!start)
	{
		mWindow.clear(sf::Color(255, 228, 196)); //делаем фон
		sf::Font font;//шрифт 
		bool b = font.loadFromFile("U:\\Evolution_v2\\Debug\\IndieFlower-Regular.ttf");//передаем нашему шрифту файл шрифта
		sf::Text text("Press mouse1 to start!", font, 65);//создаем текст
		text.setFillColor(sf::Color(205, 133, 100));// цвет текста
		text.setPosition(170, 400); // позици€ текста
		mWindow.draw(text);
		mWindow.display();
		return;
	}

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(RECT_SITE_SIZE, RECT_SITE_SIZE));
	rectangle.setOutlineColor(sf::Color(70, 29, 2));
	rectangle.setOutlineThickness(5);

	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			bool nick = 0;
			if ((i + j) % 2 == 1)
			{
				rectangle.setFillColor(sf::Color(255, 228, 196)); // светлый квадрат
			}
			else
			{
				nick = 1;
				rectangle.setFillColor(sf::Color(205, 133, 63)); // темный квадрат
			}
			if (aCell[i][j] == 1) // встретили €блоко
			{
				std::cout << nick << std::endl;
				spriteBlack.setPosition(j * 104, i * 104);
				spriteWhite.setPosition(j * 104, i * 104); // на экране оно будет тут
				if (nick == 1) mWindow.draw(spriteBlack); // рисуем €блоко
				if (nick == 0) mWindow.draw(spriteWhite); // рисуем €блоко
			}
			else
			{
				rectangle.setPosition(j * 104, i * 104);
				mWindow.draw(rectangle);
				if (aCell[i][j] > 9) // рисуем змейку
				{
					std::srand(std::time(nullptr));
					sf::CircleShape snake(48);
					if (aCell[i][j] < 20) snake.setFillColor(sf::Color(color[RandColor1][0], color[RandColor1][1], color[RandColor1][2])); //цвет змейки
					else                 snake.setFillColor(sf::Color(240, 240, 200)); //цвет змейки
					snake.setOutlineColor(sf::Color(48, 29, 2));
					snake.setOutlineThickness(5);
					snake.setPosition(j * 104, i * 104);
					mWindow.draw(snake);
				}
			}
		}
	}
	timmychinka(aTime, 380, 0, 270, 65);
	timmychinka(aTime, 650, -18, 135, 50);
	mWindow.display();
}


int Graphic::whole(char move)
{
	Button button();
	enum Direction { NUN = 0, UP = 'w', RIGHT = 'd', DOWN = 's', LEFT = 'a' };
	while (mWindow.isOpen()) // пока окно открыто
	{
		//graphic.SetBackground(sf::Color(15, 15, 15, 255));
		sf::Event event; //показывает действи€ пользовател€
		while (mWindow.pollEvent(event)) //игрок что-то делает
		{

			if (event.type == sf::Event::Closed) //закрывает ли пользователь окно
				mWindow.close(); // закрыть окно
			if (event.key.code == sf::Mouse::Left && !start) //если пользователь пользуетс€ мышкой
			{
				start = 1;
				continue;
			}
			if (!start)
			{

				continue;
			}
			if (event.type == sf::Event::KeyReleased) //вводим любой символ
			{

				if (event.key.code == sf::Keyboard::Key::D)
				{
					move = RIGHT;
					//std::cout << "d" << std::endl;
				}
				else if (event.key.code == sf::Keyboard::Key::S)
				{
					move = DOWN;
					//std::cout << "s" << std::endl;
				}
				else if (event.key.code == sf::Keyboard::Key::A)
				{
					move = LEFT;
					//std::cout << "a" << std::endl;
				}
				else if (event.key.code == sf::Keyboard::Key::W)
				{
					move = UP;
					//std::cout << "w" << std::endl;
				}
			}
		}
		return move;
	}
}

