#include "MapTile.h"

MapTile::MapTile()
{
	tileImage = NULL;
	tileName = "";
}

MapTile::MapTile(sf::Image* image, std::string name)
{
	tileImage = image;
	tileName = name;
}

void MapTile::SetImage(sf::Image *image)
{
	tileImage = image;
}

void MapTile::SetName(std::string name)
{
	tileName = name;
}

sf::Image* MapTile::GetImage()
{
	return tileImage;
}

std::string MapTile::GetName()
{
	return tileName;
}

MapTile& MapTile::Empty()
{
	return MapTile();
}

bool MapTile::IsEmpty()
{
	if (tileImage == NULL && tileName == "")
		return true;
	return false;
}