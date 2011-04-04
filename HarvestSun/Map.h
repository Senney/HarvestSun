#ifndef MAP_H
#define MAP_H

#include "includes.h"
#include "MapTile.h"

#include <iostream>
#include <fstream>

class Map
{
public:
	Map(int xsize, int ysize);

	bool LoadFromFile(std::string fileName);

private:
	MapTile** mapTiles;

};

#endif