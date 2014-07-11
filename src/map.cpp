#include <string>
#include "map.hpp"

using namespace std;

Map::Map(void)
{

}

Map::~Map(void)
{

}

enum Tile Map::char_to_tile(char c)
{
	switch (c) {
	case ' ':
		return TILE_NONE;
	case 'E':
		return TILE_EXIT;
	case 'S':
		return TILE_START;
	case '#':
		return TILE_PLAIN;
	case '=':
		return TILE_EARTH;
	default:
		throw string("Unknow tile character '") + c + "'\n";
	}
}

char Map::tile_to_char(enum Tile tile)
{
	switch (tile) {
	case TILE_NONE:
		return ' ';
	case TILE_START:
		return 'S';
	case TILE_EXIT:
		return 'E';
	case TILE_PLAIN:
		return '#';
	case TILE_EARTH:
		return '=';
	default:
		throw string("Unknow tile ") + to_string(tile) + '\n';
	}
}

/* eh for exception_header */
#define EH(x, y)                  \
	to_string(y) + ':' + to_string(x) + ": "

void Map::operator<<(std::ifstream &stream)
{
	unsigned x, y;
	char c;

	stream >> this->width >> this->height;

	this->tiles.resize(this->height);

	for (y = 0; y < this->height; y++) {
		this->tiles[y].resize(this->width);
		for (x = 0; x < this->width; x++) {
			stream >> (x == 0 && y == 0 ? skipws : noskipws) >> c;
			try {
				this->tiles[y][x] = this->char_to_tile(c);
			} catch (string &str) {
				throw EH(x + 1, y + 1) + str;
			}
		}

		stream >> c;
		if (c != '\n')
			throw EH(y + 1, this->width)
				+ "Expected end of line, got '" + c + "'\n";
	}
}

void Map::operator>>(std::ostream &stream)
{
	unsigned x, y;

	stream << this->width << ' ' << this->height << endl;

	for (y = 0; y < this->height; y++) {
		for (x = 0; x < this->width; x++) {
			stream << tile_to_char(this->tiles[y][x]);
		}
		stream << endl;
	}
}
