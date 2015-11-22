#ifndef GAME_H
#define GAME_H

#include <string>
#include <algorithm>
#include "AnimatedSprite.h"

/*
*	Game class
*	This class holds all the information for our main game loop.
*/


class Graphics;

class Game{

public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	AnimatedSprite _player;
};

#endif