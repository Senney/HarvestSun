#ifndef MENU_H
#define MENU_H

#include <sfml/Graphics.hpp>
#include <sfml/Window.hpp>
#include <sfml/System.hpp>

#include <iostream>

#include "StateManager.h"

#define MENU_OPTIONS 3
#define MENU_UPDATE_TIME 0.110

class Menu
{
public:
	Menu();

	void HandleInput(const sf::Input& input);
	void Draw(sf::RenderWindow* gameWindow);

private:
	void MoveCursor(int i);
	void UpdateCursorPosition();

	sf::Clock updateTimer;

	static const int MENU_X = 150;
	static const int MENU_Y = 100;
	static const int MENU_SPACING = 40;

	static const int MENU_START = 0;
	static const int MENU_SEL_OPTIONS = 1;
	static const int MENU_EXIT = 2;

	float lastUpdate;

	sf::Image BackgroundImage;
	sf::Image SelectorImage;
	sf::Sprite sBackgroundImage;
	sf::Sprite sSelectorImage;
	sf::Font MenuFont;

	sf::String* MenuOptions;
	bool initialized;
	int CurrentSelection;
	
};

#endif