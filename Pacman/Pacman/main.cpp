#include "board.h"
#include "pacman.h"
#include "shadow.h"
#include "speedy.h"
#include "bashful.h"
#include "pokey.h"

int main(int argc, char *argv[])
{
	Board board;
	Pacman pac;
	Shadow shadow;
	Speedy speedy;
	Bashful bash;
	Pokey pokey;

	board.LoadBoard("map.txt");

	pac.determinePosition(&board, 'i', 'j', 'I', 'J');
	shadow.determinePosition(&board, 'k', 'l', 'K', 'L');
	speedy.determinePosition(&board, 'm', 'n', 'M', 'N');
	bash.determinePosition(&board, 'o', 'p', 'O', 'P');
	pokey.determinePosition(&board, 'q', 'r', 'Q', 'R');


	getchar();
}

