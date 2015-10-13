#include "statemachine.h"
#include "board.h"

StateMachine::~StateMachine()
{
}

void StateMachine::calculateNewDestination(Vector2,char)
{
}

Vector2 StateMachine::calculateNextPosition()
{
	return Vector2();
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
