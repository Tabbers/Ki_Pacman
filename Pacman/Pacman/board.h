#pragma once
#include <string>
class Board
{
public:
	Board();
	~Board();
	bool LoadBoard(std::string);
	bool SaveBoard();
private:
	char board[28][36];

	const int BOARD_WIDTH  = 28;
	const int BOARD_HEIGHT = 36;
};