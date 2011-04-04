#include "Map.h"

Map::Map(int xsize, int ysize)
{
	mapTiles = new MapTile*[ysize];
	for (int it = 0; it < ysize; it++)
	{
		mapTiles[it] = new MapTile[xsize];
		for (int yt = 0; yt < xsize; yt++)
			mapTiles[it][yt] = MapTile::Empty();
	}
}

bool Map::LoadFromFile(std::string fileName)
{
	std::ifstream fs;
	fs.open(fileName.c_str(), std::ifstream::in);

	if (fs.fail())
		return false;

	while (!fs.eof())
	{
		std::string curLine;
		getline(fs, curLine);

		if (fs == "")
			continue;


	}

	fs.close();
}