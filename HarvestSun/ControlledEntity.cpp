#include "ControlledEntity.h"
#include "AnimatedSprite.h"

ControlledEntity::ControlledEntity() { speed = 0.04f; currentSprite = NULL; }
ControlledEntity::~ControlledEntity() { }

void ControlledEntity::AddSprite(std::string animName, AnimatedSprite &sprite)
{
	sprites[animName] = &sprite;
	if (currentSprite == NULL)
		currentSprite = &sprite;
}

AnimatedSprite* ControlledEntity::GetSprite(std::string index)
{
	if (sprites.find(index) == sprites.end())
		return NULL;
	else
		return sprites[index];
}

AnimatedSprite* ControlledEntity::GetCurrentSprite()
{
	return currentSprite;
}

void ControlledEntity::SetCurrentSprite(std::string index)
{
	currentSprite = GetSprite(index);
}

void ControlledEntity::Update(float currentTime)
{
	currentSprite->Update(currentTime);
}

void ControlledEntity::HandleInput(const sf::Input& input)
{
	if (currentSprite == NULL) return;

	sf::Vector2f curPosition = currentSprite->GetPosition();
	if (input.IsKeyDown(sf::Key::Down))
		curPosition.y += speed;
	else if (input.IsKeyDown(sf::Key::Up))
		curPosition.y -= speed;
	else if (input.IsKeyDown(sf::Key::Right))
		curPosition.x += speed;
	else if (input.IsKeyDown(sf::Key::Left))
		curPosition.x -= speed;

	currentSprite->SetPosition(curPosition);
}

void ControlledEntity::Render(sf::RenderTarget& Target) const
{
	if (currentSprite == NULL)
		return;

	Target.Draw(*(currentSprite));
}