#pragma once
#include "board.h"
#include <SFML\Graphics.hpp>
#include <windows.h>

class Display
{
public:
	Display();
	~Display();
	void SetupSprite();
	void SetupConsole();
	void CleanupSprite();
	void draw(sf::RenderWindow*);
	//Setter
	inline void setBoard(Board* boardE) { board = boardE; };

private:
	void DisplayConsole();
	void DisplaySprite(sf::RenderWindow*);
	bool LoadSprites();
private:
	Board* board;
	HANDLE  hConsole;
	sf::Sprite sprites[39];
	sf::Texture texts[36];
};
