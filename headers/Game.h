#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include "Player.h"
#include "Level.h"

class Graphics;

/*
*	Game class
*	This class holds all the information for our main game loop.
*/

class Game{
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	Player _player;
	Level _level;
};

#endif