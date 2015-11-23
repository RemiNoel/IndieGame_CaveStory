#ifndef TILE_H
#define TILE_H

#include "Globals.h"

struct SDL_Texture;
class Graphics;

class Tile{
public:
	Tile(); 
	Tile(SDL_Texture* tileset, Vector2 size, Vector2 tileSetPosition, Vector2 _position);
	~Tile();

	void update(int elapsedTime);
	void draw(Graphics &graphics);
	

private:
	SDL_Texture* _tileset;
	Vector2 _size;
	Vector2 _tilesetPosition;
	Vector2 _position;
};

#endif