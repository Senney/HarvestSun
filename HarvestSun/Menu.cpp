#include "Menu.h"

Menu::Menu()
{
	initialized = false;
	// Load images
	if (!BackgroundImage.LoadFromFile("Assets\\Images\\MenuBackground.png"))
		return;
	if (!SelectorImage.LoadFromFile("Assets\\Images\\MenuSelector.png"))
		return;
	if (!MenuFont.LoadFromFile("Assets\\Fonts\\Acens.ttf"))
		return;
	
	// Create our menu options.
	MenuOptions = new sf::String[3];
	MenuOptions[0] = sf::String("Start");
	MenuOptions[1] = sf::String("Options");
	MenuOptions[2] = sf::String("Exit");

	for (int i = 0; i < MENU_OPTIONS; i++)
	{
		MenuOptions[i].SetFont(MenuFont);
		MenuOptions[i].SetPosition(sf::Vector2f((float)MENU_X, (float)MENU_Y + i * MENU_SPACING));
	}

	sBackgroundImage.SetImage(BackgroundImage);
	sSelectorImage.SetImage(SelectorImage);

	lastUpdate = updateTimer.GetElapsedTime();

	CurrentSelection = 0;
	UpdateCursorPosition();
	initialized = true;
}

void Menu::MoveCursor(int i)
{
	CurrentSelection += i;
	if (CurrentSelection > MENU_OPTIONS - 1)
		CurrentSelection = 0;
	if (CurrentSelection < 0)
		CurrentSelection = MENU_OPTIONS - 1;
	UpdateCursorPosition();
}

void Menu::UpdateCursorPosition()
{
	sf::Vector2f Position;
	Position.x = MENU_X - 20;
	Position.y = MENU_Y + CurrentSelection * (float)MENU_SPACING + 10;
	sSelectorImage.SetPosition(Position);
}

void Menu::HandleInput(const sf::Input &input)
{
	if (!initialized)
		return;

	float currentTime = updateTimer.GetElapsedTime() - lastUpdate;
	if (currentTime < MENU_UPDATE_TIME)
		return;

	lastUpdate = updateTimer.GetElapsedTime();

	if (input.IsKeyDown(sf::Key::Down))
		MoveCursor(1);
	else if (input.IsKeyDown(sf::Key::Up))
		MoveCursor(-1);

	if (input.IsKeyDown(sf::Key::Return))
	{
		if (CurrentSelection == MENU_START)
			StateManager::Singleton()->SetCurrentState(STATE_RUNNING);
		else if (CurrentSelection == MENU_SEL_OPTIONS)
			StateManager::Singleton()->SetCurrentState(STATE_OPTIONS);
		else
			StateManager::Singleton()->SetCurrentState(STATE_EXIT);
	}
}

void Menu::Draw(sf::RenderWindow* gameWindow)
{
	if (!initialized)
		return;

	gameWindow->Draw(sBackgroundImage);
	for (int i = 0; i < MENU_OPTIONS; i++)
		gameWindow->Draw(MenuOptions[i]);
	gameWindow->Draw(sSelectorImage);
}