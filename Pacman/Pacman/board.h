#pragma once
#include <string>
#include <SDL.h>

class Board
{
public:
	Board();
	~Board();
	bool LoadBoard(std::string);
	bool SaveBoard(std::string);
	void loop(int);
	void SetupSprite();
	void CleanupSprite();
private:
	void DisplayConsole();
	void DisplaySprite();
	void Setup();
public:
	static const int BOARD_WIDTH = 29;
	static const int BOARD_HEIGHT = 32;
	char board[BOARD_WIDTH][BOARD_HEIGHT];
	char State;
private:
	SDL_Window* window;
	
};