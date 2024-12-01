// UltraEgine.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_ttf.h>
#include "../Headers/Text_Component.h"
#include <SDL_image.h>
#include <iostream>
#include "Button.h"

class UltraEgine {
public:

	UltraEgine(const int w, const int h);
	
	//create resizeabile  centered window 
	

	// rturn the window
	SDL_Window* window_get();
	void window_deestory();
	// rturn the render
	SDL_Renderer* get_GAME_SCREEN();
	SDL_Texture* get_GameTexture();
	// create reder for window and render texture

	bool init();
	bool loadmedia(Texture2D Texture2d , Button Button2d , Text_Component text_image);
	void Draw(Texture2D Texture2d, Button Button2d, Text_Component text_image);
	
	const int Width ;
	const int Height;

private:
	SDL_Window* window=NULL;
	
	SDL_Texture* GameTexture=NULL;

	TTF_Font* Text_Font = NULL;

	SDL_Rect ButtonClips[BUTTON_SPRITE_TOTAL];

     
	SDL_Rect gSpriteClips[4];
	int frame = 0;
	SDL_Renderer* GAME_SCREEN = NULL;
};

	
// TODO: Reference additional headers your program requires here.
