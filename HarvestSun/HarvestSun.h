#ifndef HARVEST_SUN_H
#define HARVEST_SUN_H

#include <sfml/Graphics.hpp>
#include <sfml/Window.hpp>
#include <sfml/System.hpp>

#include "StateManager.h"
#include "Menu.h"
#include "AnimatedSprite.h"

class HarvestSun
{
public:
	HarvestSun(int WindowWidth, int WindowHeight);
	~HarvestSun();
	void Run();

	static void SetSingleton(HarvestSun* instance);
	static HarvestSun* Singleton();

private:
	sf::RenderWindow* gameWindow;
	static HarvestSun* singleton;
	Menu mainMenu;

};

#endif