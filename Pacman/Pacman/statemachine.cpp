#include "statemachine.h"
#include "board.h"

StateMachine::~StateMachine()
{
}

void StateMachine::calculateNewDestination(Vector2,Vector2,char)
{
}

Vector2 StateMachine::calculateNextPosition(Board *board)
{
	Vector2 temp;
	temp = position;
	prevposition = position;
	temp = position + dir;
	if (Wallcheck(board, temp))
		dir = dir.rotate(-90);
	else position = position + dir;
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
				dir.x = 0;
				dir.y = -1;
				return;
			}
			if (board->board[x][y] == c2)
			{
				position.x = x;
				position.y = y;
				dir.x = 1;
				dir.y = 0;
				return;
			}
			if (board->board[x][y] == c3)
			{
				position.x = x;
				position.y = y;
				dir.x = 0;
				dir.y = 1;
				return;
			}
			if (board->board[x][y] == c4)
			{
				position.x = x;
				position.y = y;
				dir.x = -1;
				dir.y = 0;
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

void StateMachine::calculateDirection()
{
	Vector2 temp;
	if (heading.x*heading.x > heading.y*heading.y)
	{
		if (heading.x > 0)
		{
			temp.x = -1;
			temp.y = 0;
		}
		else
		{
			temp.x = 1;
			temp.y = 0;
		}
		dir = temp;
	}
	else
	{
		if (heading.x > 0)
		{
			temp.y = -1;
			temp.x = 0;
		}
		else
		{
			temp.y = 1;
			temp.x = 0;
		}
		dir = temp;
	}
}

bool StateMachine::Wallcheck(Board *board,Vector2 pos)
{
	bool result = false;

	if (board->board[pos.x][pos.y] != ' ' && board->board[pos.x][pos.y] != '.' && board->board[pos.x][pos.y] != '*') result = true;
	else result = false;

	return result;
}
