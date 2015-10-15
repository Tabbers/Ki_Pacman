#include "board.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>


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
		for (char& c : str)
		{
			board[x][y] = c;
			x++;
		}
		y++;
	}
	file.close();

	// File loaded KI must find its Position in the Array
	pac.determinePosition(this, 'i', 'j', 'I', 'J');
	shadow.determinePosition(this, 'k', 'l', 'K', 'L');
	speedy.determinePosition(this, 'm', 'n', 'M', 'N');
	bash.determinePosition(this, 'o', 'p', 'O', 'P');
	pokey.determinePosition(this, 'q', 'r', 'Q', 'R');

	bash.SetShadowRef(&shadow);
	
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
	Vector2 drawPosition;
	drawPosition = pac.GetPosition();
	board[drawPosition.x][drawPosition.y] = pac.orientedCharacter();
	drawPosition = shadow.GetPosition();
	board[drawPosition.x][drawPosition.y] = shadow.orientedCharacter();
	drawPosition = pokey.GetPosition();
	board[drawPosition.x][drawPosition.y] = pokey.orientedCharacter();
	drawPosition = speedy.GetPosition();
	board[drawPosition.x][drawPosition.y] = speedy.orientedCharacter();
	drawPosition = bash.GetPosition();
	board[drawPosition.x][drawPosition.y] = bash.orientedCharacter();

	DisplayConsole();
	DisplaySprite(window);
		
}

void Board::DisplayConsole()
{
	using namespace std;
	string screen;
	system("cls");
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			screen += board[x][y];
		}
		screen += '\n';
	}
	cout << screen;
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
			if (board[x][y] == '1')
			{
				sprites[25].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[25].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[25]);
			}
			else if (board[x][y] == '2') {
				sprites[24].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[24].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[24]);
			}
			else if (board[x][y] == '3') {
				sprites[26].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[26].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[26]);
			}
			else if (board[x][y] == '4') {
				sprites[23].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[23].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[23]);
			}
			else if (board[x][y] == '5') {
				sprites[6].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[6].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[6]);
			}
			else if (board[x][y] == '6') {
				sprites[7].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[7].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[7]);
			}
			else if (board[x][y] == '7') {
				sprites[5].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[5].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[5]);
			}
			else if (board[x][y] == '8') {
				sprites[4].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[4].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[4]);
			}

			else if (board[x][y] == '(') {
				sprites[10].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[10].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[10]);
			}
			else if (board[x][y] == ')') {
				sprites[11].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[11].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[11]);
			}
			else if (board[x][y] == '[') {
				sprites[8].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[8].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[8]);
			}
			else if (board[x][y] == ']') {
				sprites[9].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[9].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[9]);
			}
			else if (board[x][y] == '<') {
				sprites[13].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[13].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[13]);
			}
			else if (board[x][y] == '>') {
				sprites[14].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[14].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[14]);
			}
			else if (board[x][y] == '-') {
				sprites[12].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[12].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[12]);
			}
			else if (board[x][y] == 'A') {
				sprites[29].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[29].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[29]);
			}
			else if (board[x][y] == 'B') {
				sprites[28].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[28].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[28]);
			}
			else if (board[x][y] == 'C') {
				sprites[30].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[30].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[30]);
			}
			else if (board[x][y] == 'D') {
				sprites[27].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[27].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[27]);
			}
			else if (board[x][y] == 'E') {
				sprites[2].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[2].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[2]);
			}
			else if (board[x][y] == 'F') {
				sprites[3].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[3].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[3]);
			}
			else if (board[x][y] == 'G') {
				sprites[0].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[0].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[0]);
			}
			else if (board[x][y] == 'H') {
				sprites[1].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[1].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[1]);
			}
			else if (board[x][y] == 'a') {
				sprites[17].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[17].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[17]);
			}
			else if (board[x][y] == 'b') {
				sprites[18].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[18].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[18]);
			}
			else if (board[x][y] == 'c') {
				sprites[22].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[22].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[22]);
			}
			else if (board[x][y] == 'd') {
				sprites[21].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[21].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[21]);
			}
			else if (board[x][y] == 'e') {
				sprites[15].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[15].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[15]);
			}
			else if (board[x][y] == 'f') {
				sprites[16].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[16].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[16]);
			}
			else if (board[x][y] == 'g') {
				sprites[20].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[20].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[20]);
			}
			else if (board[x][y] == 'h') {
				sprites[19].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[19].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[19]);
			}
			else if (board[x][y] == '.') {
				sprites[32].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[32].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[32]);
			}
			else if (board[x][y] == '*') {
				sprites[31].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[31].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[31]);
			}
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
	// Corners
	texts[0].loadFromFile("../pacman/gfx/tiles/corner_bottom_left.png");
	sprites[0].setTexture(texts[0]);
	texts[1].loadFromFile("../pacman/gfx/tiles/corner_bottom_right.png");
	sprites[1].setTexture(texts[1]);
	texts[2].loadFromFile("../pacman/gfx/tiles/corner_top_left.png");
	sprites[2].setTexture(texts[2]);
	texts[3].loadFromFile("../pacman/gfx/tiles/corner_top_right.png");
	sprites[3].setTexture(texts[3]);

	texts[4].loadFromFile("../pacman/gfx/tiles/outercorner_bottom_left.png");
	sprites[4].setTexture(texts[4]);
	texts[5].loadFromFile("../pacman/gfx/tiles/outercorner_bottom_right.png");
	sprites[5].setTexture(texts[5]);
	texts[6].loadFromFile("../pacman/gfx/tiles/outercorner_top_left.png");
	sprites[6].setTexture(texts[6]);
	texts[7].loadFromFile("../pacman/gfx/tiles/outercorner_top_right.png");
	sprites[7].setTexture(texts[7]);

	texts[8].loadFromFile("../pacman/gfx/tiles/outercorner_narrow_bottom_left.png");
	sprites[8].setTexture(texts[8]);
	texts[9].loadFromFile("../pacman/gfx/tiles/outercorner_narrow_bottom_right.png");
	sprites[9].setTexture(texts[9]);
	texts[10].loadFromFile("../pacman/gfx/tiles/outercorner_narrow_top_left.png");
	sprites[10].setTexture(texts[10]);
	texts[11].loadFromFile("../pacman/gfx/tiles/outercorner_narrow_top_right.png");
	sprites[11].setTexture(texts[11]);

	// Ghostpit
	texts[12].loadFromFile("../pacman/gfx/tiles/door.png");
	sprites[12].setTexture(texts[12]);
	texts[13].loadFromFile("../pacman/gfx/tiles/gate_left.png");
	sprites[13].setTexture(texts[13]);
	texts[14].loadFromFile("../pacman/gfx/tiles/gate_right.png");
	sprites[14].setTexture(texts[14]);

	//Noses
	texts[15].loadFromFile("../pacman/gfx/tiles/outernose_bottom_left.png");
	sprites[15].setTexture(texts[15]);
	texts[16].loadFromFile("../pacman/gfx/tiles/outernose_bottom_right.png");
	sprites[16].setTexture(texts[16]);
	texts[17].loadFromFile("../pacman/gfx/tiles/outernose_top_left.png");
	sprites[17].setTexture(texts[17]);
	texts[18].loadFromFile("../pacman/gfx/tiles/outernose_top_right.png");
	sprites[18].setTexture(texts[18]);
	texts[19].loadFromFile("../pacman/gfx/tiles/outernose_left_bottom.png");
	sprites[19].setTexture(texts[19]);
	texts[20].loadFromFile("../pacman/gfx/tiles/outernose_left_top.png");
	sprites[20].setTexture(texts[20]);
	texts[21].loadFromFile("../pacman/gfx/tiles/outernose_right_bottom.png");
	sprites[21].setTexture(texts[21]);
	texts[22].loadFromFile("../pacman/gfx/tiles/outernose_right_top.png");
	sprites[22].setTexture(texts[22]);

	//Walls
	texts[23].loadFromFile("../pacman/gfx/tiles/outerwall_left.png");
	sprites[23].setTexture(texts[23]);
	texts[24].loadFromFile("../pacman/gfx/tiles/outerwall_right.png");
	sprites[24].setTexture(texts[24]);
	texts[25].loadFromFile("../pacman/gfx/tiles/outerwall_top.png");
	sprites[25].setTexture(texts[25]);
	texts[26].loadFromFile("../pacman/gfx/tiles/outerwall_bottom.png");
	sprites[26].setTexture(texts[26]);
	texts[27].loadFromFile("../pacman/gfx/tiles/wall_left.png");
	sprites[27].setTexture(texts[27]);
	texts[28].loadFromFile("../pacman/gfx/tiles/wall_right.png");
	sprites[28].setTexture(texts[28]);
	texts[29].loadFromFile("../pacman/gfx/tiles/wall_top.png");
	sprites[29].setTexture(texts[29]);
	texts[30].loadFromFile("../pacman/gfx/tiles/wall_bottom.png");
	sprites[30].setTexture(texts[30]);

	//Points
	texts[31].loadFromFile("../pacman/gfx/tiles/big_dot.png");
	sprites[31].setTexture(texts[31]);
	texts[32].loadFromFile("../pacman/gfx/tiles/dot.png");
	sprites[32].setTexture(texts[32]);
	return result;
}
