




#include "../Headers/Button.h"
#include <iostream>


Button::Button()
{
	
	mPosition.x = 0;
	mPosition.y = 0;
	mCurrentSprite= BUTTON_SPRITE_MOUSE_OUT;
}

void Button::SetPosition(int Posx, int Posy)
{
	mPosition.x = Posx;
	mPosition.y = Posy;
}

void Button::HandleEvent(SDL_Event* e, SDL_Window* w)
{
	// if the user use mouse event

	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
		// get mouse position 
		int x;
		int y;
		SDL_GetMouseState(&x, &y);
		
			// check if the mouse is inside the button 
			std::cout << x << std::endl << y;
			bool inside = true;
			//mouse is left of button  
			if (x < mPosition.x) {
				inside = false;
			}
			//mouse is right of button  
			else if (x > mPosition.x + BUTTON_WIDTH) {
				inside = false;
			}
			//mouse is above of button 
			else if (y < mPosition.y && y != BUTTON_HIEGHT) {
				inside = false;
			}
			//mouse is down of button 
			else if (y > mPosition.y + BUTTON_HIEGHT) {
				inside = false;
			}

			// if mouse out the button 
			if (!inside) {
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			else {
				// mouse inside button 
				switch (e->type)
				{
					// mouse hover
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;
					// mouse pressed
				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;
				case SDL_MOUSEBUTTONUP:
					// mouse realse
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
					break;

				}
			}
		
	}
}

void Button::render_button(Texture2D ButtonSpriteSheet, SDL_Rect ButtonClips[BUTTON_SPRITE_TOTAL], SDL_Renderer* m1GAME_SCREEN)
{
	
	ButtonSpriteSheet.load_texture_from_file("button", m1GAME_SCREEN);
	
	ButtonSpriteSheet.render(mPosition.x, mPosition.y,m1GAME_SCREEN, &ButtonClips[mCurrentSprite]);
}







