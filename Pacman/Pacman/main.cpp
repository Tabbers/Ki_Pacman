#include "board.h"
#include <iostream>

int main(int argc, char *argv[])
{
	int steps = 1;

	Board board;
	
	board.LoadBoard("map.txt");
	board.SetupSprite();
	board.loop(steps);
	std::cout << "calculated "+std::to_string(steps)+" steps";
	getchar();
	board.SaveBoard("result.txt");
	board.CleanupSprite();
	return 0;
}

