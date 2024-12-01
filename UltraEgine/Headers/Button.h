#pragma once
#include <SDL_events.h>
#include <SDL.h>
#include "Texture2D.h"

static int BUTTON_WIDTH = 300;
static int BUTTON_HIEGHT =100;
const int BUTTON_COUNT = 4;

   enum ButtonSprite {
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};



class Button {
public:

	// Initializes variables
	Button();
	// sets top left position 
	void SetPosition(int Posx, int Posy);
	// hadule button events
	void HandleEvent(SDL_Event* e, SDL_Window *w);
	void render_button(Texture2D ButtonSpriteSheet, SDL_Rect ButtonClips[BUTTON_SPRITE_TOTAL], SDL_Renderer* m1GAME_SCREEN);
	

	// render button texture
	
	

private:
	// top left position 
	SDL_Point mPosition;

	//Currently used global sprite
	ButtonSprite mCurrentSprite;
};

