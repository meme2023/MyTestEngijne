// Mygame.cpp : Defines the entry point for the application.
//

#include "Mygame.h"



// MimiEngine.cpp : Defines the entry point for the application.
//

using namespace std;

UltraEgine Engine(1000, 500);



// Global text
TTF_Font* Text_Font = NULL;
Texture2D gFooTexture{ 4 };
Texture2D gBackground;
Text_Component my_font;
static const int n = 4;
SDL_Rect gSpriteClips[n];
SDL_Texture* GameTexture;
Texture2D ButtonSpriteSheet;
SDL_Rect ButtonClips[BUTTON_SPRITE_TOTAL];
int frame = 0;
void close();


Button TESTBUTTON;




void close()
{
	//Free loaded image

	//Free global font
	TTF_CloseFont(Text_Font);
	Text_Font = NULL;//Free global font
	//destory texture
	SDL_DestroyTexture(GameTexture);
	
	gFooTexture.free();

	//Destroy window
	SDL_DestroyWindow(Engine.window_get());

	SDL_DestroyRenderer(Engine.get_GAME_SCREEN());
	Engine.window_deestory();

	//Quit SDL subsystems
	SDL_Quit();
	IMG_Quit();
}




int main(int argc, char* args[]) {


	//Current animation frame
	int frame = 0;
	std::cout << gFooTexture.get_width() << "\n" << gFooTexture.get_height();
	SDL_Rect fillRect = { 0,0 ,50,50 };
	bool quit = false;
	SDL_Event e;
	//Modulation component
	Uint8 a = 255;
	//Angle of rotation
	double degrees = -180.0;
	
	if (!Engine.init()) {
		std::cout << "faild to inlize\n";
	}
	else {

		if (!Engine.loadmedia(gFooTexture, TESTBUTTON, my_font)) {
			std::cout << "faild to load image\n";
		}
		else {
			
			while (!quit) {
				// hadle the event in que
				while (SDL_PollEvent(&e) != 0)
				{
					// user reqsest quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}


					// Hundle button events
			
						TESTBUTTON.HandleEvent(&e,Engine.window_get());
					


				}


				Engine. Draw(gFooTexture, TESTBUTTON, my_font);



			}

		}

	}

	close();

	return 0;
}
