#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <map>
#include <vector>

#include "Sprite.h"
#include "Globals.h"

class Graphics;

/*	AnimatedSprite class
*	Holds logic for animating sprites
*/

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY, float timeToUpdate);

	/*	void playAnimation
	*	Plays the animation provided if it's not already playing
	*/

	void playAnimation(std::string animation, bool once = false);

	/*	void update
	*	Updates the animated sprite (timer)
	*/
	void update(int elapsedTime);

	/*	void draw	
	*	Draws the sprite to the screen
	*/
	void draw(Graphics &graphics, int x, int y);

	/*	void setupAnimations
	*	A required function that sets up all animation for a sprite
	*/
	virtual void setupAnimation();

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;
	
	/*	void addAnimation
	*	Adds an animation to the map of animations for the sprite
	*/
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	/*	void resetAnimations
	*	Resets all animations associated with this sprite
	*/
	void resetAnimations();

	/*	void stopAnimations
	*	stops the current animation
	*/
	void stopAnimations();

	/* void setVisible
	*	Changes the visibility of the animated sprite
	*/
	void setVisible(bool visible);

	/*	void animationDone
	*	Logic that happens when an animation ends
	*/
	void animationDone(std::string currentAnimation);

private:
	std::map<std::string, std::vector<SDL_Rect>> _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;
	
};

#endif