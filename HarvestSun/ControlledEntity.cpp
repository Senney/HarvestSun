#include "ControlledEntity.h"

ControlledEntity::ControlledEntity() { }
ControlledEntity::~ControlledEntity() { }

void ControlledEntity::AddSprite(std::string animName, AnimatedSprite &sprite)
{
	sprites[animName] = &sprite;
}