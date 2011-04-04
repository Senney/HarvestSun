#include "MapTileController.h"

MapTileController* MapTileController::singleton = 0;

MapTileController::MapTileController()
{
}

MapTileController* MapTileController::GetSingleton()
{
	if (singleton == 0)
		singleton = new MapTileController();
	return singleton;
}

void MapTileController::AddTile(MapTile newtile)
{
	tiles[newtile.GetName()] = newtile;
}

MapTile& MapTileController::GetTile(std::string tile)
{
	if (tiles.find(tile) == tiles.end())
		return MapTile::Empty();
	return tiles[tile];
}