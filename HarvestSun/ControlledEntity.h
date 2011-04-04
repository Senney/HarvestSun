#ifndef CONTROLLED_ENTITY_H
#define CONTROLLED_ENTITY_H

#include <sfml/Graphics.hpp>
#include <sfml/Window.hpp>
#include <sfml/System.hpp>
#include <map>

class AnimatedSprite;

class ControlledEntity : public sf::Drawable
{
public:
	ControlledEntity();
	~ControlledEntity();

	void AddSprite(std::string animName, AnimatedSprite& sprite);
	AnimatedSprite* GetSprite(std::string index);
	AnimatedSprite* GetCurrentSprite();

	void SetCurrentSprite(std::string index);

	void Update(float currentTime);

	virtual void HandleInput(const sf::Input& input);

private:
	virtual void Render(sf::RenderTarget& Target) const;

	AnimatedSprite* currentSprite;

	std::map<std::string, AnimatedSprite*> sprites;
	float speed;
};

#endif