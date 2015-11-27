#ifndef HUD_H
#define HUD_H

#include "Sprite.h"
#include "Player.h"

class Graphics;

class HUD{
public:
	HUD();
	HUD(Graphics &graphics, Player &player);
	void update(int elapsedTime);
	void draw(Graphics &graphics);

private:
	Player _player;

	//Health sprites
	Sprite _healthBarSprite;
	Sprite _healthNumber1;
	Sprite _currentHealthBar;

	//Exp sprites
	Sprite _lvWord;
	Sprite _lvNumber;
	Sprite _expBar;

	//Weapon info sprites
	Sprite _slash;
	Sprite _dashes;
};

#endif