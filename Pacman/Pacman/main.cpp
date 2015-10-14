#include "board.h"
#include <iostream>

int main(int argc, char *argv[])
{
	Board board;
	int steps = 1;
	bool calculateSteps = true;

	sf::RenderWindow window(sf::VideoMode(board.BOARD_WIDTH*8, board.BOARD_HEIGHT*8), "pacman");

	board.LoadBoard("map.txt");
	board.SetupSprite();
	int step = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (calculateSteps && step < steps) window.close();
			step++;
		}
		window.clear(sf::Color::Black);
		board.loop(&window);
		window.display();
	}
	std::cout << "calculated "+std::to_string(steps)+" steps";
	getchar();
	board.SaveBoard("result.txt");
	board.CleanupSprite();
	return 0;
}

