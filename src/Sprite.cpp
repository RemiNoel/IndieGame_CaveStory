#include "Sprite.h"
#include "Globals.h"
/*
	Game class
	This class holds all the information the sprites used for the chactacter.
*/

Sprite::Sprite(){

}
Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
	float posX, float posY) : 
		_x(posX),
		_y(posY)
{
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));

	if (!(this->_spriteSheet)) {
		printf("IMG_Load: %s\n", IMG_GetError());
		// handle error
	}
}

Sprite::~Sprite(){

}

void Sprite::draw(Graphics &graphics, int x, int y){
	SDL_Rect destinationRectangle = { x, y, this->_sourceRect.w * globals::SPRITE_SCALE, this->_sourceRect.h * globals::SPRITE_SCALE };
	graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectangle);
}

void Sprite::update(){

}