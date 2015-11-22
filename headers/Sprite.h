#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Graphics.h"

class Graphics;

/*	Sprite class
*	Holds all information for individual sprites
*/

class Sprite{
public:
	Sprite();

	// Create and displays the sprite on screen
	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY);
	
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);

protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet; 

private:
	float _x, _y;
};

#endif