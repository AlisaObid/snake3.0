#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <SFML/Graphics.hpp> 
#include <iostream>
#include <vector>
#include <string>

class Graphic
{
public:
	Graphic();
	void drawMap(std::vector<std::vector<int>> aCell);
	int whole(char move);

private:
	sf::RenderWindow mWindow;
};
#endif //GRAPHIC_H