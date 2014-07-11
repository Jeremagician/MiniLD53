#ifndef MAP_H_
#define MAP_H_

#include <fstream>
#include <vector>

enum Tile {
	TILE_NONE,
	TILE_START,
	TILE_EXIT,
	TILE_PLAIN,
	TILE_EARTH,
};

class Map {
private:
	unsigned width, height;
	std::vector<std::vector<enum Tile> > tiles;

	enum Tile char_to_tile(char c);
	char tile_to_char(enum Tile tile);
public:
	Map(void);
	~Map(void);

	void operator<<(std::ifstream &stream);
	void operator>>(std::ostream &stream);
};

#endif /* MAP_H_ */
