#include"../Headers/Text_Component.h"


Text_Component::Text_Component() :Texture2D()
{
}

bool Text_Component::load_text_font_fromfile(SDL_Renderer* m1GAME_SCREEN, TTF_Font** gFont, std::string textureText, SDL_Color textcolor)
{
	free();
	// reder the surface
	SDL_Surface* textsurface = TTF_RenderText_Solid(*gFont, textureText.c_str(), textcolor);
	if (textsurface == NULL) {
		std::cout << "Unable to render text surface!SDL_ttf Error % s\n" << TTF_GetError();
	}

	else {
		mTexture = SDL_CreateTextureFromSurface(m1GAME_SCREEN, textsurface);
		if (mTexture == NULL) {
			std::cout << "Unalbe to create SDL ERROR" << std::endl << SDL_GetError();
		}
		else {
			Texture2D_Width = textsurface->w;
			Texture2D_Hieght = textsurface->h;
		}
	}
	SDL_FreeSurface(textsurface);
	return mTexture != NULL;
}
