#ifndef MAP_H
#define MAP_H

#include "includes.h"
#include "MapTile.h"
#include "MapTileController.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class Map
{
public:
	Map();
	Map(int xsize, int ysize);

	bool LoadFromFile(std::string fileName);

private:
	MapTile** mapTiles;

	int map_size_x, map_size_y;
	std::string rootFolder;

	std::vector<std::string> GetParts(std::string str, const char token);

	void InitArray(int xsize, int ysize);
	void GetMapSize(std::string str);

	void ParseSet(std::vector<std::string> parts);
	void ParseDefine(std::vector<std::string> parts);
};

#endif