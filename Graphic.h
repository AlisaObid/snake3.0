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
	void drawMap(std::vector<std::vector<int>> aCell, std::string aTime, std::string aSize);
	void drawMenu();
	void timmychinka(std::string aTime, int x, int y, int sizex, int sizey, int xtext, int ytext, int textsize);
	int whole(char move);
	bool start = 0;

private:
	std::vector<std::vector<int>> color; 
	int RandColor1;
	int RandColor2;

	sf::Sprite spriteWhite; // ������ ������ �� ����� ����
	sf::Texture textureWhite; //������� �������� ������ �� ����� ����
	bool isLoadedWhite; // ������� �� �������� ������ �� ����� ����

	sf::Sprite spriteBlack; // ������ ������ �� ������ ����
	bool isLoadedBlack; // ������� �� �������� ������ �� ������ ����
	sf::Texture textureBlack; //������� �������� ������ �� ������ ����
;
	sf::RenderWindow mWindow;
};
#endif //GRAPHIC_H