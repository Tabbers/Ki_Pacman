#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "pacman.h"
#include "shadow.h"
#include "speedy.h"
#include "bashful.h"
#include "pokey.h"

class Board
{
public:
	Board();
	~Board();
	bool LoadBoard(std::string);
	bool SaveBoard(std::string);
	void loop(sf::RenderWindow*);
	void SetupSprite();
	void CleanupSprite();
private:
	void DisplayConsole();
	void DisplaySprite(sf::RenderWindow*);
	void Setup();
	bool LoadSprites();
public:
	static const int BOARD_WIDTH = 28;
	static const int BOARD_HEIGHT = 31;
	char board[BOARD_WIDTH][BOARD_HEIGHT];
	char State;
private:
	sf::Sprite sprites[33];
	sf::Texture texts[33];
	Pacman pac;
	Shadow shadow;
	Speedy speedy;
	Bashful bash;
	Pokey pokey;
};