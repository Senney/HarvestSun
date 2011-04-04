#ifndef MAP_TILE_CONTROLLER_H
#define MAP_TILE_CONTROLLER_H

#include <map>

#include "MapTile.h"
#include "includes.h"

class MapTileController
{
public:
	void AddTile(MapTile newtile);
	MapTile& GetTile(std::string tile);

	static MapTileController* GetSingleton();

private:
	MapTileController();

	std::map<std::string, MapTile> tiles;

	static MapTileController* singleton;

};

#endif