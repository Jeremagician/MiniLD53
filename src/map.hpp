#ifndef MAP_H_
#define MAP_H_

#include <fstream>
#include <vector>

enum class Direction {
	TOP = (1 << 0),
	RIGHT = (1 << 1),
	BOTTOM = (1 << 2),
	LEFT = (1 << 3),
};

enum class TileBox {
	PLAIN,
	EDGE,
	CORNER,
	CORNER_IN,
};

class Tile
{
protected:
	TileBox   box;
	Direction facing;
	Direction rotation;

	enum {
		TILE_NONE,
		TILE_EXIT,
		TILE_START,
		TILE_PLAIN,
		TILE_EARTH,
		TILE_LAST,
	};

	/* It would be better to have something like enum inheritance  */
	int type;

public:
	Tile(void);
	~Tile(void);

	void operator<<(std::ifstream &stream);
	void operator>>(std::ostream &stream);
};

class Map
{
private:
	unsigned width, height;
	std::vector<std::vector<Tile> > tiles;
public:
	Map(void);
	~Map(void);

	void operator<<(std::ifstream &stream);
	void operator>>(std::ostream &stream);
};

#endif /* MAP_H_ */
