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
	while (gameWindow->IsOpened())
	{
		const sf::Input &windowInput = gameWindow->GetInput();

		sf::Event event;
		while (gameWindow->GetEvent(event))
		{
			if (event.Type == sf::Event::Closed)
				gameWindow->Close();
		}

		gameWindow->Clear();
		int state = StateManager::Singleton()->GetCurrentState();
		switch (state)
		{
		case STATE_PAUSE:
			mainMenu.HandleInput(windowInput);
			mainMenu.Draw(gameWindow);
			break;
		case STATE_RUNNING:
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