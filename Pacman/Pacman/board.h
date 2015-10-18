#pragma once
#include <string>
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
	void Setup();
	void loop();
private:
	bool IntersectionCheck(Vector2 postition);
public:
	static const int BOARD_WIDTH = 28;
	static const int BOARD_HEIGHT = 31;
	char board[BOARD_WIDTH][BOARD_HEIGHT];
	char state;
private:
	Pacman pac;
	Shadow shadow;
	Speedy speedy;
	Bashful bash;
	Pokey pokey;
};