#include <iostream>
#include <string>
#include "map.hpp"

using namespace std;

Tile::Tile(void)
{

}

Tile::~Tile(void)
{

}

void Tile::operator<<(std::ifstream &stream)
{
	char c;

	stream >> noskipws >> c;

	switch (c) {
	case ' ':
		this->type = TILE_NONE; break;
	case 'E':
		this->type = TILE_EXIT; break;
	case 'S':
		this->type = TILE_START; break;
	case '#':
		this->type = TILE_PLAIN; break;
	case '=':
		this->type = TILE_EARTH; break;
	default:
		throw string("Unknow tile character '") + c + "'\n";
	}
}

void Tile::operator>>(std::ostream &stream)
{
	char c;

	switch (this->type) {
	case TILE_NONE:
		c = ' '; break;
	case TILE_START:
		c = 'S'; break;
	case TILE_EXIT:
		c = 'E'; break;
	case TILE_PLAIN:
		c = '#'; break;
	case TILE_EARTH:
		c = '='; break;
	default:
		throw string("Unknow tile ") + to_string(this->type) + '\n';
	}

	stream << c;
}

Map::Map(void)
{

}

Map::~Map(void)
{

}

/* EH for Exception Header */
#define EH(x, y)                                        \
	to_string(y) + ':' + to_string(x) + ": "

void Map::operator<<(std::ifstream &stream)
{
	unsigned x, y;
	char c;

	stream >> this->width >> this->height;

	this->tiles.resize(this->height);

	for (y = 0; y < this->height; y++) {
		stream >> noskipws >> c;
		if (c != '\n')
			throw EH(y + 1, this->width)
				+ "Expected end of line, got '" + c + "'\n";

		this->tiles[y].resize(this->width);

		for (x = 0; x < this->width; x++) {
			try {
				this->tiles[y][x] << stream;
			} catch (string &str) {
				throw EH(x + 1, y + 1) + str;
			}
		}
	}
}

void Map::operator>>(std::ostream &stream)
{
	unsigned x, y;

	stream << this->width << ' ' << this->height << endl;

	for (y = 0; y < this->height; y++) {
		for (x = 0; x < this->width; x++) {
			try {
				this->tiles[y][x] >> stream;
			} catch (string &str) {
				throw EH(x + 1, y + 1) + str;
			}
		}
		stream << endl;
	}
}
