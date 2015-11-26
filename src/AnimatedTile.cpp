#include "AnimatedTile.h"
#include "Graphics.h"

AnimatedTile::AnimatedTile(std::vector<Vector2> tilesetPosition, int duration,
	SDL_Texture* tileset, Vector2 size, Vector2 position) :
	Tile(tileset, size, tilesetPosition.at(0), position),
	_tilesetPosition(tilesetPosition),
	_duration(duration),
	_tileToDraw(0)
{}

void AnimatedTile::update(int elapsedTime){
	//Timer code
	if (this->_amountOfTime <= 0){
		if (this->_tileToDraw == this->_tilesetPosition.size() - 1){
			this->_tileToDraw = 0;
		}
		else{
			this->_tileToDraw++;
		}
		this->_amountOfTime = this->_duration;
	}
	else{
		this->_amountOfTime -= elapsedTime;
	}
		
	Tile::update(elapsedTime);
}

void AnimatedTile::draw(Graphics &graphics){
	SDL_Rect destRect = { this->_position.x, this->_position.y,
		this->_size.x * globals::SPRITE_SCALE, this->_size.y *globals::SPRITE_SCALE };
	SDL_Rect sourceRect = { this->_tilesetPosition.at(this->_tileToDraw).x, this->_tilesetPosition.at(this->_tileToDraw).y, 
		this->_size.x, this->_size.y };

	graphics.blitSurface(this->_tileset, &sourceRect, &destRect);
}