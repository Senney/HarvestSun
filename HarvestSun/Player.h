#include "ControlledEntity.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public ControlledEntity
{
public:
	Player();

	void SetSpeed(float speed);
	float GetSpeed();
};

#endif