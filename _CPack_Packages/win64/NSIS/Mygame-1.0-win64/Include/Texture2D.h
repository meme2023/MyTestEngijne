#pragma once

#include<SDL.h>
#include <string>
extern bool load;
class Texture2D {
public:
    Texture2D(int Tsize);
	 Texture2D();
	~Texture2D();
	// load the image
    bool load(std::string path, SDL_Renderer** m1GAME_SCREEN);

	// render the image
	void render(int x, int y, SDL_Renderer** m1GAME_SCREEN, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Deallocates texture
	void free();
	void set_color(Uint8 red, Uint8 green, Uint8 blue);
	void set_Alpha(Uint8 alpha);
	void set_beldingmode(SDL_BlendMode blend);
	int get_width();
	int get_height();





protected:

	// texture diemision
	SDL_Texture* mTexture{};
	int Texture2D_Width{};
	int Texture2D_Hieght{};
	int Texturesize{};
};
