#include "ControlledEntity.h"

ControlledEntity::ControlledEntity() { }
ControlledEntity::~ControlledEntity() { }

void ControlledEntity::AddSprite(std::string animName, AnimatedSprite &sprite)
{
	sprites[animName] = &sprite;
}

AnimatedSprite* ControlledEntity::GetSprite(std::string index)
{
	if (sprites.find(index) == sprites.end)
		return NULL;
	else
		return sprites[index];
}