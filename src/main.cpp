#include <iostream>
#include <cstdlib>
#include "Game.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main(void)
{
	/*RenderWindow window(VideoMode(800,600), "MiniLD 53!");

	while(window.isOpen())
	{
		Event event;
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyReleased:
				if(event.key.code == Keyboard::Escape)
					window.close();
				break;
			}
		}

		window.clear();

		window.display();
	} */

	Game::Start();
	return EXIT_SUCCESS;
};
