#include "Board.h"
#include <fstream>
#include <sstream>

Board::Board()
{
}


Board::~Board()
{
}

bool Board::LoadBoard(std::string load)
{
	using namespace std;
	string str;
	ifstream file(load);
	Setup();
	int y = 0;
	while (getline(file, str))
	{
		int x = 0;
		y++;
		for (char& c : str)
		{
			board[x][y] = c;
			x++;
		}
	}
	file.close();
	return true;
}
bool Board::SaveBoard(std::string save)
{
	using namespace std;
	ofstream file(save);
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{ 
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			file.put(board[x][y]);
		}
		file.put('\n');
	}
	file.close();
	return true;
}

void Board::Setup()
{
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			board[x][y]=' ';
		}
	}
}
