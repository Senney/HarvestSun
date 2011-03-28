#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#define STATE_PAUSE 0
#define STATE_RUNNING 1
#define STATE_OPTIONS 2
#define STATE_EXIT 3

class StateManager
{
public:
	void SetCurrentState(int state) { currentState = state; }
	int GetCurrentState() { return currentState; }

	static StateManager* Singleton() {
		if (singleton == 0)
			singleton = new StateManager;
		return singleton;
	}

private:
	int currentState;
	static StateManager* singleton;
};

#endif