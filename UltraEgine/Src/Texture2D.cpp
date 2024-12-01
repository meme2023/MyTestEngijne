
#include"../Headers/Texture2D.h"
#include <SDL_image.h>
#include <iostream>



 Texture2D::Texture2D(int Tsize) :Texturesize(Tsize)
{
	// initialize
	mTexture = { NULL };
	Texture2D_Width = { 0 };
	Texture2D_Hieght = { 0 };
	Texturesize = { 1 };
}

Texture2D::Texture2D()
{

	// initialize
	mTexture = { NULL };
	Texture2D_Width = { 0 };
	Texture2D_Hieght = { 0 };
	Texturesize = { 1 };
}

Texture2D::~Texture2D()
{
	// delocate
	free();
}

bool Texture2D::load(std::string path, SDL_Renderer* m1GAME_SCREEN)
{
	//Get rid of preexisting texture
	free();
	SDL_Texture* NEW_TEXTURE = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		std::cout << "unale to load the image SDL IMAGE ERROR \n" << path.c_str() << "\n" << SDL_GetError();
	}
	else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		//Create texture from surface pixels
		NEW_TEXTURE = SDL_CreateTextureFromSurface(m1GAME_SCREEN, loadedSurface);

		if (NEW_TEXTURE == NULL) {
			std::cout << "unale to create the texture SDL TEXTURE ERROR \n" << path.c_str() << "\n" << SDL_GetError();
		}
		else {
			// add the dimssions to the image
			Texture2D_Width = loadedSurface->w;
			Texture2D_Hieght = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);

	}
	mTexture = NEW_TEXTURE;
	return mTexture != NULL;
}

void Texture2D::render(int x, int y, SDL_Renderer* m1GAME_SCREEN, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{

	// we have to know what texture
	SDL_Rect renderqaud = { x,y,Texture2D_Width,Texture2D_Hieght };
	if (clip != NULL) {
		renderqaud.w = clip->w * Texturesize;
		renderqaud.h = clip->h * Texturesize;
	}
	SDL_RenderCopyEx(m1GAME_SCREEN, mTexture, clip, &renderqaud, angle, center, flip);
}



void Texture2D::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		Texture2D_Width = 0;
		Texture2D_Hieght = 0;
		//mGAME_SCREEN = NULL;
		//SDL_DestroyRenderer(mGAME_SCREEN);
	}
}

void Texture2D::set_color(Uint8 red, Uint8 green, Uint8 blue)
{

	//Modulate texture
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Texture2D::set_Alpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void Texture2D::set_beldingmode(SDL_BlendMode blend)
{
	SDL_SetTextureBlendMode(mTexture, blend);
}



int Texture2D::get_width()
{
	return Texture2D_Width;
}

int Texture2D::get_height()
{
	return Texture2D_Hieght;
}

void Texture2D::load_texture_from_file(std::string nameT, SDL_Renderer* m1GAME_SCREEN)
{
	free();
	SDL_Texture* NEW_TEXTURE = NULL;

	std::string deafalutpath = "C:\\Users\\memeo\\Desktop\\c++\\Mygame\\Assets\\Texture\\water.png";
	for (auto i = 0; i < Texturename.size();i++) {
		std::string basepath = "C:\\Users\\memeo\\Desktop\\c++\\Mygame\\Assets\\Texture\\" + Texturename[i] + ".png";


		if (basepath!= "C:\\Users\\memeo\\Desktop\\c++\\Mygame\\Assets\\Texture\\" + Texturename[i] + ".png") {
			std::cout << " Could not find file";

			SDL_Surface* loadedSurface = IMG_Load(deafalutpath.c_str());
		}
		else
		{
			if (nameT == Texturename[i]) {
				
				SDL_Surface* loadedSurface = IMG_Load(basepath.c_str());

				//std::cout << " found file";
				SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
				// remove the blurring effect in sprite
				SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
				//Create texture from surface pixels
				NEW_TEXTURE = SDL_CreateTextureFromSurface(m1GAME_SCREEN, loadedSurface);

				if (NEW_TEXTURE == NULL) {
					std::cout << "unale to create the texture SDL TEXTURE ERROR \n" << basepath.c_str() << "\n" << SDL_GetError();
				}
				else {
					// add the dimssions to the image
					Texture2D_Width = loadedSurface->w;
					Texture2D_Hieght = loadedSurface->h;
				}
				//Get rid of old loaded surface
				SDL_FreeSurface(loadedSurface);
			}
		}
		mTexture = NEW_TEXTURE;

	}
}

	


