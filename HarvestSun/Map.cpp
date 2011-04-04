#include "Map.h"

Map::Map(int xsize, int ysize)
{
	InitArray(xsize, ysize);
}

Map::Map()
{
	map_size_x = 0;
	map_size_y = 0;
}

void Map::InitArray(int xsize, int ysize)
{
	if (xsize == 0 || ysize == 0)
		return;

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

	int i = 0;
	while (!fs.eof())
	{
		std::string curLine;
		getline(fs, curLine);

		if (curLine == "" || curLine.find("//") != std::string::npos)
			continue;

		// Line #1
		if (i == 0) 
		{
			// The first line should be the file size.
			GetMapSize(curLine);
			InitArray(map_size_x, map_size_y);
			if (mapTiles == NULL)
			{
				std::cout << "Could not load map file: Error reading map size." << '\n';
				return false;
			}
			i++;
		}

		std::vector<std::string> parts = GetParts(curLine, ' ');

		if (parts[0] == "define")
		{
			ParseDefine(parts);
		}
		else if (parts[0] == "set")
		{
			ParseSet(parts);
		}
	}

	fs.close();

	return true;
}

void Map::ParseDefine(std::vector<std::string> parts)
{
	if (parts[0] != "define")
		return;

	if (parts.size() > 6 && parts[1] == "tile")
	{
		std::string texLocation = rootFolder + parts[2];
		std::string tilename = parts[3];
		sf::Image tileImage;
		if (!tileImage.LoadFromFile(texLocation))
		{
			std::cout << "ERROR: Could not find texture at: " << texLocation << "." << '\n';
			return;
		}

		MapTile tempTile = MapTile(&tileImage, tilename);
		MapTileController::GetSingleton()->AddTile(tempTile);
	}
}

void Map::ParseSet(std::vector<std::string> parts)
{
	if (parts[0] != "set")
		return;

	if (parts.size() == 4 && parts[1] == "root" && parts[2] == "folder")
	{
		rootFolder = parts[3];
	}
}

void Map::GetMapSize(std::string str)
{
	std::vector<std::string> parts = GetParts(str, ',');
	if (parts.size() != 2)
		return;

	map_size_x = atoi(parts[0].c_str());
	map_size_y = atoi(parts[1].c_str());
}

std::vector<std::string> Map::GetParts(std::string str, const char token)
{
	std::vector<std::string> parts;

	std::string curPart;
	std::istringstream ss(str);
	while (getline(ss, curPart, token))
	{
		parts.push_back(curPart);
	}

	return parts;
}