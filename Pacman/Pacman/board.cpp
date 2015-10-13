#include "board.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "pacman.h"
#include "shadow.h"
#include "speedy.h"
#include "bashful.h"
#include "pokey.h"



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

void Board::loop(int maxloops)
{
	Pacman pac;
	Shadow shadow;
	Speedy speedy;
	Bashful bash;
	Pokey pokey;

	pac.determinePosition(this, 'i', 'j', 'I', 'J');
	shadow.determinePosition(this, 'k', 'l', 'K', 'L');
	speedy.determinePosition(this, 'm', 'n', 'M', 'N');
	bash.determinePosition(this, 'o', 'p', 'O', 'P');
	pokey.determinePosition(this, 'q', 'r', 'Q', 'R');

	for (int i = 0; i < maxloops; i++)
	{
		DisplayConsole();
		DisplaySprite();
	}

}

void Board::DisplayConsole()
{
	using namespace std;
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			cout << board[x][y];
		}
		cout << '\n';
	}
}

void Board::SetupSprite()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	// Create a Window in the middle of the screen
	window=0;

	window = SDL_CreateWindow("Pacman",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		8*BOARD_WIDTH, 8*BOARD_HEIGHT,
		SDL_WINDOW_SHOWN);
}

void Board::DisplaySprite()
{


}

void Board::CleanupSprite()
{	
	// Cleanup and Quit
	SDL_DestroyWindow(window);
	SDL_Quit();
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

