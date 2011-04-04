#ifndef MAP_TILE_H
#define MAP_TILE_H

#include "includes.h"

class MapTile
{
public:
	MapTile();
	MapTile(sf::Image* image, std::string name);

	sf::Image* GetImage();
	void SetImage(sf::Image* image);

	std::string GetName();
	void SetName(std::string name);

	static MapTile& Empty();
	bool IsEmpty();

private:
	sf::Image* tileImage;
	std::string tileName;

};

#endif