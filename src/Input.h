#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <map>

/*
	Input class
	Keeps track of keyboard state
*/


class Input{

public:
	//to reset the keys that are no longer relevant. This gets called a the beginning the the game loop.
	void beginNewFrame();

	//This get called when a key has been released
	void keyUpEvent(const SDL_Event& event);

	//This gets called when a key has been pressed
	void keyDownEvent(const SDL_Event& event);

	//This check if a certain key was pressed during the current frame
	bool wasKeyPressed(SDL_Scancode key);

	//Check if a certain key was released during the current frame
	bool wasKeyReleased(SDL_Scancode key);

	//Check if a certain key is currently being held
	bool isKeyHeld(SDL_Scancode key);

private:
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
};

#endif