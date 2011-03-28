#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(sf::Image* spriteSheet, int totalFrames, int x, int y, int cellWidth, int cellHeight, float timePerFrame, float curTime)
{
	SetSpriteSheet(spriteSheet);
	SetCellWidth(cellWidth);
	SetCellHeight(cellHeight);
	SetSheetPosition(sf::Vector2i(x, y));
	SetTimePerFrame(timePerFrame);

	lastTime = curTime;
	currentFrame = 0;
	maxFrame = totalFrames;
	isRunning = true;
	doesLoop = true;

	SetupSprite();
}

AnimatedSprite::~AnimatedSprite()
{
	m_SpriteSheet = NULL;
	spriteParts = NULL;
}

void AnimatedSprite::SetupSprite()
{
	if (m_SpriteSheet == NULL)
		return;

	// Here we will split our image into the required amount of parts.
	spriteParts = new sf::Image[maxFrame]();
	//spriteParts = (sf::Image*)malloc(sizeof(sf::Image) * maxFrame);
	for (int x = 0; x < maxFrame; x++)
	{
		int xPosition = x * width + xpos;
		if (xPosition > (int)m_SpriteSheet->GetWidth())
		{
			std::cout << "ERROR: Spritesheet: Creating sprite defined outside of bounds." << '\n';
			return;
		}

		sf::Image temp(width, height, sf::Color(128, 128, 128, 255));
		temp.Copy(*(m_SpriteSheet), 0, 0, sf::IntRect(xPosition, ypos, xPosition + width, ypos + height), false);
		
		spriteParts[x] = temp;
	}

	if (currentFrame <= maxFrame)
		currentSprite.SetImage(spriteParts[currentFrame]);
	else
		currentSprite.SetImage(spriteParts[0]);
}

void AnimatedSprite::Update(float currentTime)
{
	if (!isRunning)
		return;
	if (!doesLoop && maxFrame == (currentFrame + 1))
		return;
	if ((currentTime - lastTime) < frameTime)
		return;

	int nextFrame = currentFrame + 1;
	if (nextFrame >= maxFrame)
		nextFrame = 0;
	
	currentSprite.SetImage(spriteParts[nextFrame]);
	lastTime = currentTime;
	currentFrame = nextFrame;
}

void AnimatedSprite::Draw(sf::RenderWindow* gameWindow)
{
	gameWindow->Draw(currentSprite);
}

void AnimatedSprite::DrawDebug(sf::RenderTarget* gameWindow)
{
	sf::Sprite debugSprite;

	for (int i = 0; i < maxFrame; i++)
	{
		debugSprite.SetPosition(100.0f, 100.0f + (32.0f * i));
		debugSprite.SetImage(spriteParts[i]);
		gameWindow->Draw(debugSprite);
	}
}

void AnimatedSprite::Render(sf::RenderTarget& Target) const
{
	Target.Draw(currentSprite);
}

void AnimatedSprite::SetSheetPosition(sf::Vector2i newPosition)
{
	xpos = newPosition.x;
	ypos = newPosition.y;
}

void AnimatedSprite::SetSheetPosition(int x, int y)
{
	xpos = x;
	ypos = y;
}

sf::Vector2i AnimatedSprite::GetSheetPosition()
{
	return sf::Vector2i(xpos, ypos);
}

void AnimatedSprite::SetCellHeight(int height)
{
	this->height = height;
}

void AnimatedSprite::SetCellWidth(int width)
{
	this->width = width;
}

int AnimatedSprite::GetCellWidth()
{
	return width;
}

int AnimatedSprite::GetCellHeight()
{
	return height;
}

void AnimatedSprite::SetSpriteSheet(sf::Image* spriteSheet)
{
	m_SpriteSheet = spriteSheet;
}

sf::Image* AnimatedSprite::GetSpriteSheet()
{
	return m_SpriteSheet;
}

void AnimatedSprite::ToggleRun()
{
	isRunning = !isRunning;
}

void AnimatedSprite::ToggleLoop()
{
	doesLoop = !doesLoop;
}

bool AnimatedSprite::GetRunStatus()
{
	return isRunning;
}

bool AnimatedSprite::GetLoopStatus()
{
	return doesLoop;
}