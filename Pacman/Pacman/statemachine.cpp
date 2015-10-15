#include "statemachine.h"
#include "board.h"

StateMachine::~StateMachine()
{
}

void StateMachine::calculateNewDestination(Vector2,Vector2,char)
{
}

Vector2 StateMachine::calculateNextPosition()
{
	Vector2 temp;
	temp = position;
	prevposition = position;
	// Calc next position;
	if(heading.x*heading.x > heading.y*heading.y)
	{
		if(temp.x>0) temp.x - 1;
		else temp.x + 1;
		position = temp;
	}
	else
	{

		if (temp.y>0) temp.x - 1;
		else temp.y + 1;
		position = temp;
	}
	return position;
}

void StateMachine::determinePosition(Board*board ,char c1, char c2, char c3, char c4)
{
	for (int y = 0; y < board->BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < board->BOARD_WIDTH; x++)
		{
			if (board->board[x][y] == c1)
			{
				position.x = x;
				position.y = y;
				heading.x = 0;
				heading.y = -1;
				return;
			}
			if (board->board[x][y] == c2)
			{
				position.x = x;
				position.y = y;
				heading.x = 1;
				heading.y = 0;
				return;
			}
			if (board->board[x][y] == c3)
			{
				position.x = x;
				position.y = y;
				heading.x = 0;
				heading.y = 1;
				return;
			}
			if (board->board[x][y] == c4)
			{
				position.x = x;
				position.y = y;
				heading.x = -1;
				heading.y = 0;
				return;
			}
		}
	}
}

char StateMachine::orientedCharacter()
{
	char result =' ';
	if (heading.x*heading.x > heading.y*heading.y)
	{
		if (heading.x > 0) result = representation[0];
		else result = representation[1];
	}
	else
	{
		if (heading.y>0) result = representation[2];
		else result = representation[3];
	}

	return result;
}
