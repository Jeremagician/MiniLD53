#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "map.hpp"

using namespace std;
using namespace sf;

int main(void)
{
	Map map;
	ifstream file("../proposal/file_format.txt");

	try {
		map << file;
		map >> cout;
	} catch (string &str) {
		cerr << str;
	}

	return EXIT_SUCCESS;
};
