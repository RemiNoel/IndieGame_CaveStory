#include "Graphics.h"
#include <SDL.h>

/*
	Graphics class
	Holds all the information about the graphics of the game.
*/


Graphics::Graphics(){
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "CaveStory :)");
}

Graphics::~Graphics(){
	SDL_DestroyWindow(this->_window);
}