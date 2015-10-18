#include "board.h"
#include "display.h"
#include <SFML\Graphics.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
	//Set to the septs beeing calculated
	int steps = 1;
	//Set if continious loop or set amounts of steps
	bool calculateSteps = true;

	// Set board and dispaly, pass reference of board to display
	Board board;
	Display display;
	display.setBoard(&board);

	sf::RenderWindow window(sf::VideoMode(board.BOARD_WIDTH*8, board.BOARD_HEIGHT*8), "pacman");

	board.LoadBoard("map.txt");
	display.SetupSprite();
	display.SetupConsole();
	int step = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			
		}
		//if (calculateSteps && step < steps) window.close();
		window.clear(sf::Color::Black);
		board.loop();
		display.draw(&window);
		window.display();
		step++;
	}
	std::cout << "calculated "+std::to_string(steps)+" steps";
	getchar();
	board.SaveBoard("result.txt");
	display.CleanupSprite();
	return 0;
}

