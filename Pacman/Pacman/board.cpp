#include "board.h"
#include <fstream>
#include <string>
#include <sstream>
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
	string temp;
	ifstream file(load);
	Setup();
	getline(file, str);
	temp = str.substr(str.find('=')+1,str.npos);
	if (temp == "pursuit") state = 'r';
	if (temp == "patrol") state = 'p';
	if (temp == "escape") state = 'e';
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

void Board::Setup()
{
	// Fill all Fields of the Board with blank Spaces
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			board[x][y] = ' ';
		}
	}
}

void Board::loop()
{
	// Check if Ghosts are allowed to recalculate their heading
	if (IntersectionCheck(shadow.getPosition()))
	{
		shadow.calculateNewDestination(pac.getPosition(), pac.getDirection(), state);
	}
	if (IntersectionCheck(bash.getPosition()))
	{
		bash.calculateNewDestination(pac.getPosition(), pac.getDirection(), state);
	}
	if (IntersectionCheck(speedy.getPosition()))
	{
		speedy.calculateNewDestination(pac.getPosition(), pac.getDirection(), state);
	}
	if (IntersectionCheck(pokey.getPosition()))
	{
		pokey.calculateNewDestination(pac.getPosition(), pac.getDirection(), state);
	}

	// Calculate the position for the current gameframe
	shadow.calculateNextPosition(this);
	bash.calculateNextPosition(this);
	speedy.calculateNextPosition(this);
	pokey.calculateNextPosition(this);

	//Write the updated position into the char array
	Vector2 drawPosition;
	drawPosition = pac.calculateNextPosition(this);
	board[drawPosition.x][drawPosition.y] = pac.orientedCharacter();
	drawPosition = pac.getPrevPosition();
	board[drawPosition.x][drawPosition.y] = ' ';

	drawPosition = shadow.getPosition();
	board[drawPosition.x][drawPosition.y] = shadow.orientedCharacter();
	drawPosition = shadow.getPrevPosition();
	board[drawPosition.x][drawPosition.y] = ' ';

	drawPosition = pokey.getPosition();
	board[drawPosition.x][drawPosition.y] = pokey.orientedCharacter();
	drawPosition = pokey.getPrevPosition();
	board[drawPosition.x][drawPosition.y] = ' ';


	drawPosition = speedy.getPosition();
	board[drawPosition.x][drawPosition.y] = speedy.orientedCharacter();
	drawPosition = speedy.getPrevPosition();
	board[drawPosition.x][drawPosition.y] = ' ';

	drawPosition = bash.getPosition();
	board[drawPosition.x][drawPosition.y] = bash.orientedCharacter();
	drawPosition = bash.getPrevPosition();
	board[drawPosition.x][drawPosition.y] = ' ';



}
bool Board::IntersectionCheck(Vector2 position)
{
	bool result = false;
	int paths = 0;

	if (board[position.x - 1][position.y] == ' ' || board[position.x - 1][position.y] == '.' || board[position.x - 1][position.y] == '*') paths++;
	if (board[position.x + 1][position.y] == ' ' || board[position.x + 1][position.y] == '.' || board[position.x + 1][position.y] == '*') paths++;
	if (board[position.x][position.y - 1] == ' ' || board[position.x][position.y - 1] == '.' || board[position.x][position.y - 1] == '*') paths++;
	if (board[position.x][position.y + 1] == ' ' || board[position.x][position.y + 1] == '.' || board[position.x][position.y + 1] == '*') paths++;

	if (paths > 2) result = true;
	return result;
}
