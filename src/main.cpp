#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

using namespace std;
using namespace sf;

int main(void)
{
	RenderWindow window(VideoMode(1000,800), "MiniLD 53!");

	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);

	while(window.isOpen())
	{
		Event event;
		while(window.pollEvent(event))
		{
			if(event.type == Event::Closed)
				window.close();

			window.clear();

			window.display();
		}

	}

	return EXIT_SUCCESS;
};
