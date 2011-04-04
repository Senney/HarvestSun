#include "HarvestSun.h"

HarvestSun* HarvestSun::singleton = 0;

HarvestSun::HarvestSun(int WindowWidth, int WindowHeight)
{
	gameWindow = new sf::RenderWindow(sf::VideoMode(WindowWidth, WindowHeight), "Harvest Sun 0.1a");
	StateManager::Singleton()->SetCurrentState(STATE_PAUSE);
	HarvestSun::SetSingleton(this);
}

void HarvestSun::SetSingleton(HarvestSun* instance)
{
	singleton = instance;
}

HarvestSun* HarvestSun::Singleton()
{
	return singleton;
}

HarvestSun::~HarvestSun()
{
	delete gameWindow;
}

void HarvestSun::Run()
{
	sf::Clock GameClock;

	sf::Image* characterSpriteSheet = new sf::Image();
	characterSpriteSheet->LoadFromFile("Assets\\Images\\PlayerTile.png");
	AnimatedSprite test1(characterSpriteSheet, 3, 0, 0, 16, 16, 80, GameClock.GetElapsedTime());
	AnimatedSprite test2(characterSpriteSheet, 3, 0, 16, 16, 16, 80, GameClock.GetElapsedTime());

	ControlledEntity PlayerEntity;
	PlayerEntity.AddSprite("walkRight", test1);

	float lastTime = GameClock.GetElapsedTime();

	while (gameWindow->IsOpened())
	{
		const sf::Input &windowInput = gameWindow->GetInput();

		sf::Event event;
		while (gameWindow->GetEvent(event))
		{
			if (event.Type == sf::Event::Closed)
				gameWindow->Close();
		}

		gameWindow->Clear(sf::Color(255, 255, 255, 255));
		int state = StateManager::Singleton()->GetCurrentState();
		switch (state)
		{
		case STATE_PAUSE:
			mainMenu.HandleInput(windowInput);
			mainMenu.Draw(gameWindow);
			break;
		case STATE_RUNNING:
			PlayerEntity.HandleInput(windowInput);
			PlayerEntity.Update(GameClock.GetElapsedTime());
			gameWindow->Draw(PlayerEntity);
			break;
		case STATE_OPTIONS:
			break;
		case STATE_EXIT:
			gameWindow->Close();
			break;
		}

		gameWindow->Display();

	}
}