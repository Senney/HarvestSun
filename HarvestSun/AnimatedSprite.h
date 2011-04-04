#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <sfml/Graphics.hpp>
#include <sfml/Window.hpp>

#include <iostream>
#include <sstream>

class AnimatedSprite : public sf::Drawable
{
public:
	AnimatedSprite(sf::Image* spriteSheet, int totalFrames, int x, int y, int cellWidth, int cellHeight, float timePerFrame, float curTime);
	~AnimatedSprite();

	void Update(float currentTime);
	
	void SetTimePerFrame(float timePerFrame) { frameTime = timePerFrame / 1000.0f; }
	float GetTimePerFrame() { return frameTime; }
	
	void ToggleRun();
	void ToggleLoop();

	bool GetRunStatus();
	bool GetLoopStatus();

	void SetSheetPosition(sf::Vector2i newPosition);
	void SetSheetPosition(int x, int y);
	sf::Vector2i GetSheetPosition();

	void SetCellHeight(int height);
	void SetCellWidth(int width);
	int GetCellWidth();
	int GetCellHeight();

	void SetSpriteSheet(sf::Image* spriteSheet);
	sf::Image* GetSpriteSheet();

	//void SetPosition(float x, float y);
	//sf::Vector2f GetPosition();

	void Draw(sf::RenderWindow* gameWindow);

	void DrawDebug(sf::RenderTarget* gameWindow);

private:
	void SetupSprite();

	virtual void Render(sf::RenderTarget& Target) const;

	float frameTime, lastTime; // Time per frame.
	int width, height, xpos, ypos;
	bool isRunning;
	bool doesLoop;

	int currentFrame, maxFrame;

	float currentTime;

	sf::Sprite currentSprite;
	
	sf::Image* m_SpriteSheet;
	sf::Image* spriteParts;
};

#endif 