#include "display.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "vector2.h" 


Display::Display()
{
}


Display::~Display()
{
}
void Display::draw(sf::RenderWindow* window)
{
	DisplayConsole();
	DisplaySprite(window);
}

void Display::DisplayConsole()
{
	using namespace std;
	int k;
	system("cls");
	for (int y = 0; y < board->BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < board->BOARD_WIDTH; x++)
		{
			switch (board->board[x][y])
			{
			// walls
			case '1': case '2': case '3': case '4': case '5': case '6': case '7': case'8': case '(': case ')': case'[': case ']':
			case '<': case '>': case 'A': case 'B': case 'C': case 'D': case 'E': case'F': case 'G': case 'H': case'a': case 'b':
			case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': 
				k = 1;
				break;
			//Pacman
			case 'i': case 'j': case 'I': case 'J':
				k = 14;
				break;
			//Shadow
			case 'k': case 'l': case 'K': case'L':
				k = 12;
				break;
			//Speedy
			case 'm': case 'n': case'M': case 'N':
				k = 13;
				break;
			//Bashful
			case 'o': case 'p': case 'O': case 'P':
				k = 11;
				break;
			//pokey
			case 'q': case 'r': case 'Q': case'R':
				k = 6;
				break;
			//pills and dots
			case '.': case '*':
				k = 15;
				break;
			//Doors
			case '-':
				k = 13;
				break;
				//Doors
			case ' ':
				k = 0;
				break;
			}
			SetConsoleTextAttribute(hConsole, k);
			cout << board->board[x][y];
		}
		cout << '\n';
	}
}

void Display::SetupConsole()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Display::SetupSprite()
{
	LoadSprites();
}

void Display::DisplaySprite(sf::RenderWindow* window)
{
	for (int y = 0; y < board->BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < board->BOARD_WIDTH; x++)
		{
			switch (board->board[x][y])
			{
			case '1':
				sprites[25].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[25].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[25]);
				break;
			case '2':
				sprites[24].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[24].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[24]);
				break;
			case '3':
				sprites[26].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[26].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[26]);
				break;
			case '4':
				sprites[23].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[23].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[23]);
				break;
			case '5':
				sprites[6].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[6].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[6]);
				break;
			case '6':
				sprites[7].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[7].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[7]);
				break;
			case '7':
				sprites[5].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[5].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[5]);
				break;
			case '8':
				sprites[4].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[4].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[4]);
				break;
			case '(':
				sprites[10].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[10].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[10]);
				break;
			case ')':
				sprites[11].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[11].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[11]);
				break;
			case '[':
				sprites[8].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[8].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[8]);
				break;
			case ']':
				sprites[9].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[9].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[9]);
				break;
			case '<':
				sprites[13].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[13].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[13]);
				break;
			case '>':
				sprites[14].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[14].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[14]);
				break;
			case '-':
				sprites[12].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[12].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[12]);
				break;
			case 'A':
				sprites[29].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[29].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[29]);
				break;
			case 'B':
				sprites[28].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[28].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[28]);
				break;
			case 'C':
				sprites[30].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[30].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[30]);
				break;
			case 'D':
				sprites[27].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[27].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[27]);
				break;
			case 'E':
				sprites[2].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[2].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[2]);
				break;
			case 'F':
				sprites[3].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[3].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[3]);
				break;
			case 'G':
				sprites[0].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[0].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[0]);
				break;
			case 'H':
				sprites[1].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[1].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[1]);
				break;
			case 'a':
				sprites[17].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[17].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[17]);
				break;
			case 'b':
				sprites[18].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[18].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[18]);
				break;
			case 'c':
				sprites[22].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[22].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[22]);
				break;
			case 'd':
				sprites[21].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[21].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[21]);
				break;
			case 'e':
				sprites[15].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[15].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[15]);
				break;
			case 'f':
				sprites[16].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[16].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[16]);
				break;
			case 'g':
				sprites[20].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[20].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[20]);
				break;
			case 'h':
				sprites[19].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[19].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[19]);
				break;
			case '.':
				sprites[32].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[32].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[32]);
				break;
			case '*':
				sprites[31].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[31].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[31]);
				break;
			case 'i':
				sprites[37].setTextureRect(sf::IntRect(100, 0, 100, 100));
				sprites[37].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[37].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[37]);
				break;
			case 'j':
				sprites[37].setTextureRect(sf::IntRect(400, 0, 100, 100));
				sprites[37].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[37].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[37]);
				break;
			case 'I':
				sprites[37].setTextureRect(sf::IntRect(700, 0, 100, 100));
				sprites[37].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[37].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[37]);
				break;
			case 'J':
				sprites[37].setTextureRect(sf::IntRect(1000, 0, 100, 100));
				sprites[37].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[37].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[37]);
				break;
			case 'k':
				sprites[33].setTextureRect(sf::IntRect(100, 0, 100, 100));
				sprites[33].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[33].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[33]);

				sprites[38].setTextureRect(sf::IntRect(0, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;
			case 'l':
				sprites[33].setTextureRect(sf::IntRect(100, 0, 100, 100));
				sprites[33].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[33].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[33]);

				sprites[38].setTextureRect(sf::IntRect(100, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;
			case 'K':
				sprites[33].setTextureRect(sf::IntRect(100, 0, 100, 100));
				sprites[33].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[33].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[33]);

				sprites[38].setTextureRect(sf::IntRect(200, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;
			case 'L':
				sprites[33].setTextureRect(sf::IntRect(100, 0, 100, 100));
				sprites[33].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[33].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[33]);

				sprites[38].setTextureRect(sf::IntRect(300, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;
			case 'n':
				sprites[34].setTextureRect(sf::IntRect(300, 0, 100, 100));
				sprites[34].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[34].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[34]);

				sprites[38].setTextureRect(sf::IntRect(0, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break; 
			case 'm':
				sprites[34].setTextureRect(sf::IntRect(300, 0, 100, 100));
				sprites[34].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[34].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[34]);

				sprites[38].setTextureRect(sf::IntRect(100, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break; 
			case 'N':
				sprites[34].setTextureRect(sf::IntRect(300, 0, 100, 100));
				sprites[34].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[34].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[34]);

				sprites[38].setTextureRect(sf::IntRect(200, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break; 
			case 'M':
				sprites[34].setTextureRect(sf::IntRect(300, 0, 100, 100));
				sprites[34].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[34].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[34]);

				sprites[38].setTextureRect(sf::IntRect(300, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;
			case 'o':
				sprites[35].setTextureRect(sf::IntRect(500, 0, 100, 100));
				sprites[35].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[35].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[35]);

				sprites[38].setTextureRect(sf::IntRect(0, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;
			case 'p': 
				sprites[35].setTextureRect(sf::IntRect(500, 0, 100, 100));
				sprites[35].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[35].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[35]);

				sprites[38].setTextureRect(sf::IntRect(100, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;
			case 'O': 
				sprites[35].setTextureRect(sf::IntRect(500, 0, 100, 100));
				sprites[35].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[35].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[35]);

				sprites[38].setTextureRect(sf::IntRect(200, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;
			case 'P':
				sprites[35].setTextureRect(sf::IntRect(500, 0, 100, 100));
				sprites[35].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[35].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[35]);

				sprites[38].setTextureRect(sf::IntRect(300, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;
			case 'q':
				sprites[36].setTextureRect(sf::IntRect(700, 0, 100, 100));
				sprites[36].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[36].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[36]);

				sprites[38].setTextureRect(sf::IntRect(0, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break; 
			case 'r':
				sprites[36].setTextureRect(sf::IntRect(700, 0, 100, 100));
				sprites[36].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[36].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[36]);

				sprites[38].setTextureRect(sf::IntRect(100, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;
			case 'Q':
				sprites[36].setTextureRect(sf::IntRect(700, 0, 100, 100));
				sprites[36].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[36].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[36]);

				sprites[38].setTextureRect(sf::IntRect(200, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;
			case 'R':
				sprites[36].setTextureRect(sf::IntRect(700, 0, 100, 100));
				sprites[36].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[36].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[36]);

				sprites[38].setTextureRect(sf::IntRect(300, 0, 100, 100));
				sprites[38].setPosition(sf::Vector2f(x * 8, y * 8));
				sprites[38].setScale(sf::Vector2f(0.08f, 0.08f));
				window->draw(sprites[38]);
				break;

			}
		}
	}
}

void Display::CleanupSprite()
{

}


bool Display::LoadSprites()
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

	//Ghosts
	texts[33].loadFromFile("../pacman/gfx/sprites/monster.png");
	//Shadow
	sprites[33].setTexture(texts[33]);
	//speedy
	sprites[34].setTexture(texts[33]);
	//bashful
	sprites[35].setTexture(texts[33]);
	//pokey
	sprites[36].setTexture(texts[33]);
	
	//pacman
	texts[34].loadFromFile("../pacman/gfx/sprites/pacman.png");
	sprites[37].setTexture(texts[34]);
	sprites[37].setTextureRect(sf::IntRect(100, 0, 100, 100));

	texts[35].loadFromFile("../pacman/gfx/sprites/eyes.png");
	sprites[38].setTexture(texts[35]);

	return result;
}