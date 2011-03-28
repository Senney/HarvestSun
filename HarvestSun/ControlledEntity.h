#include <sfml/Graphics.hpp>
#include <sfml/Window.hpp>
#include <sfml/System.hpp>

#include <map>

#include "AnimatedSprite.h"

class ControlledEntity : public sf::Drawable
{
public:
	ControlledEntity();
	~ControlledEntity();

	void AddSprite(std::string animName, AnimatedSprite& sprite);
	AnimatedSprite* GetSprite(std::string index);

	virtual void HandleInput(const sf::Input input);

private:
	virtual void Render(sf::RenderTarget& Target);

	std::map<std::string, AnimatedSprite*> sprites;

};