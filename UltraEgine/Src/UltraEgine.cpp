



#include"../Headers/UltraEgine.h"

// UltraEgine.cpp : Defines the entry point for the application.


UltraEgine::UltraEgine(const int w, const int h):Width(w) ,Height(h)
{

}


// rturn the window
SDL_Window* UltraEgine::window_get()
{
	return window;
}

void UltraEgine::window_deestory()
{
   window=NULL;
   GameTexture = NULL;
   GAME_SCREEN =NULL;
}

SDL_Renderer* UltraEgine::get_GAME_SCREEN()
{
	return GAME_SCREEN;
}



SDL_Texture* UltraEgine::get_GameTexture()
{
	return GameTexture;
}





bool UltraEgine::init()

{
	bool succses = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

		std::cout << "SDL could not initialize! SDL Error: %s\n" << SDL_GetError();
		succses = false;

	}
	else {
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		// create window screen
		window = SDL_CreateWindow("my test game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		if (window_get() == NULL) {
			std::cout << "SDL failed to create window! SDL Error: %s\n" << SDL_GetError();
			succses = false;
		}
		else {

			// create redering
			GAME_SCREEN = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
			// make render target the texture
			GameTexture = SDL_CreateTexture(GAME_SCREEN, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, Width, Height);



			if (get_GAME_SCREEN() == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());

				succses = false;
			}
			else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(get_GAME_SCREEN(), 5, 15, 97, 0xFF);

				// INITIALIZE PNG LOADING
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {

					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					succses = false;
				}

				//INITIALIZE text.ttf
				if (TTF_Init() == -1) {
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					succses = false;
				}

			}
		}
	}
	return succses;
}

 bool UltraEgine::loadmedia(Texture2D Texture2d, Button Button2d, Text_Component text_image)
{
		bool succses = true;
		




		
			
			// top left
			gSpriteClips[0].x = 0;
			gSpriteClips[0].y = 32 * 5;
			gSpriteClips[0].w = 32;
			gSpriteClips[0].h = 32;
			// rop right
			gSpriteClips[1].x = 0;
			gSpriteClips[1].y = 32 * 6;
			gSpriteClips[1].w = 32;
			gSpriteClips[1].h = 32;
			// bottom left
			gSpriteClips[2].x = 0;
			gSpriteClips[2].y = 32 * 7;
			gSpriteClips[2].w = 32;
			gSpriteClips[2].h = 32;

			gSpriteClips[3].x = 0;
			gSpriteClips[3].y = 32 * 8;
			gSpriteClips[3].w = 32;
			gSpriteClips[3].h = 32;

		




	


	for (int i = 0; i < BUTTON_COUNT; ++i) {
		ButtonClips[i].x = 0;
		ButtonClips[i].y = i * 100;
		ButtonClips[i].w = BUTTON_WIDTH;
		ButtonClips[i].h = BUTTON_HIEGHT;
	}

	Button2d.SetPosition(200, 50);
	return succses;
	
		
	}


void UltraEgine::Draw(Texture2D Texture2d, Button Button2d, Text_Component text_image)
{
	Texture2d.load_texture_from_file("mys", GAME_SCREEN);
	Text_Font = TTF_OpenFont("C:\\Users\\memeo\\Desktop\\c++\\Mygame\\Assets\\Fonts\\ARCADECLASSIC.TTF", 28);
	if (Text_Font == NULL) {
		std::cout << "failed to load the font sdl_ttf error" << std::endl << TTF_GetError();
	}
	else {
		SDL_Color textColor = { 0, 0, 0 };
		if (!text_image.load_text_font_fromfile(get_GAME_SCREEN(), &Text_Font, "My Name Is Mimi Sucss", textColor)) {
			printf("Failed to render text texture!\n");
			
		}
	}
	Uint8 a = 255;
	SDL_Point c = { 0,0 };
	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;
	//Current animation frame

	SDL_Rect* currentClip = &gSpriteClips[frame / 16];
	
	Texture2d.Texturesize =2;
	SDL_SetRenderTarget(GAME_SCREEN, GameTexture);
	// create clear screen
	SDL_RenderClear(get_GAME_SCREEN());

	//Button2d.render_button(Texture2d, ButtonClips, get_GAME_SCREEN());

	Texture2d.render((Width - currentClip->w) / 2, (Height - currentClip->h) / 2, GAME_SCREEN, currentClip, NULL, &c, flipType);
	text_image.render(60, 70, get_GAME_SCREEN());


	//renove the texeture
	SDL_SetRenderTarget(GAME_SCREEN, NULL);
	//Now render the texture target to our screen
	SDL_RenderClear(GAME_SCREEN);
	SDL_RenderCopyEx(GAME_SCREEN, GameTexture, NULL, NULL, 0, NULL, SDL_FLIP_NONE);

	Texture2d.set_Alpha(a);


	SDL_RenderPresent(get_GAME_SCREEN());

	Texture2d.set_color(255, 255, 255);
	//ainmating
	++frame;
	if (frame / 16 >= n) {
		frame = 0;
	}

}

