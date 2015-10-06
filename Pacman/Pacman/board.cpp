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

bool Board::SaveBoard()
{
	return true;
}
