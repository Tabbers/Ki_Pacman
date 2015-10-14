#include "board.h"
#include <fstream>
#include <sstream>
#include <iostream>


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

	// File loaded KI must find its Position in the Array
	pac.determinePosition(this, 'i', 'j', 'I', 'J');
	shadow.determinePosition(this, 'k', 'l', 'K', 'L');
	speedy.determinePosition(this, 'm', 'n', 'M', 'N');
	bash.determinePosition(this, 'o', 'p', 'O', 'P');
	pokey.determinePosition(this, 'q', 'r', 'Q', 'R');
	
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

void Board::loop(sf::RenderWindow* window)
{
		DisplayConsole();
		DisplaySprite(window);
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
	LoadSprites();
}

void Board::DisplaySprite(sf::RenderWindow* window)
{
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			if (board[x][y] == '1') window->draw(sprites[25]);
			if (board[x][y] == '2') window->draw(sprites[0]);
			if (board[x][y] == '3') window->draw(sprites[0]);
			if (board[x][y] == '4') window->draw(sprites[0]);
			if (board[x][y] == '5') window->draw(sprites[0]);



		}
	}
}

void Board::CleanupSprite()
{
}

void Board::Setup()
{
	// Fill all Fields of the Board with blank Spaces
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			board[x][y]=' ';
		}
	}
}
bool Board::LoadSprites()
{
	bool result = true;
	sf::Texture text;
	// Corners
	text.loadFromFile("../pacman/gfx/tiles/corner_bottom_left.png");
	sprites[0].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/corner_bottom_right.png");
	sprites[1].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/corner_top_left.png");
	sprites[2].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/corner_top_right.png");
	sprites[3].setTexture(text);

	text.loadFromFile("../pacman/gfx/tiles/outercorner_bottom_left.png");
	sprites[4].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outercorner_bottom_right.png");
	sprites[5].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outercorner_top_left.png");
	sprites[6].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outercorner_top_right.png");
	sprites[7].setTexture(text);

	text.loadFromFile("../pacman/gfx/tiles/outercorner_narrow_bottom_left.png");
	sprites[8].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outercorner_narrow_bottom_right.png");
	sprites[9].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outercorner_narrow_top_left.png");
	sprites[10].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outercorner_narrow_top_right.png");

	// Ghostpit
	sprites[11].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/door.png");
	sprites[12].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/gate_left.png");
	sprites[13].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/gate_right.png");

	//Noses
	sprites[14].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outernose_bottom_left.png");
	sprites[15].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outernose_bottom_right.png");
	sprites[16].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outernose_top_left.png");
	sprites[17].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outernose_top_right.png");
	sprites[18].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outernose_left_bottom.png");
	sprites[19].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outernose_left_top.png");
	sprites[20].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outernose_right_bottom.png");
	sprites[21].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outernose_right_top.png");
	sprites[22].setTexture(text);

	//Walls
	text.loadFromFile("../pacman/gfx/tiles/outerwall_left.png");
	sprites[23].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outerwall_right.png");
	sprites[24].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outerwall_top.png");
	sprites[25].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/outerwall_bottom.png");
	sprites[26].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/wall_left.png");
	sprites[27].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/wall_right.png");
	sprites[28].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/wall_top.png");
	sprites[29].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/wall_bottom.png");
	//Points
	sprites[30].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/big_dot.png");
	sprites[31].setTexture(text);
	text.loadFromFile("../pacman/gfx/tiles/dot.png");
	sprites[32].setTexture(text);
	return result;
}
