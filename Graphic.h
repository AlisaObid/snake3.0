#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <SFML/Graphics.hpp> 
#include <iostream>
#include <vector>
#include <string>

class Graphic
{
public:
	Graphic(sf::RenderWindow& aWindow);
	//написать текст
	void DrawText(std::string aString, 
		std::int16_t x, std::int16_t y, sf::Color aColor); //нарисовать текст
	void SetBackground(sf::Color); //фон
	void DrawMap(std::vector<std::vector<int>> aMap); //нарисовать карту
private:
	sf::RenderWindow& mWindow; //окно
	sf::Font mFont; //создаем шрифт
	sf::Text mText; //создаем переменную для вывода текста
};
#endif //GRAPHIC_H