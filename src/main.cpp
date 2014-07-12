#include "Game.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char **argv)
{
	Game game(argc, argv);
	return game.exec();
};
