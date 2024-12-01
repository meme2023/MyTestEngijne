#pragma once
#include"../Headers/Texture2D.h"
#include"string"
#include<SDL_ttf.h>
#include <iostream>
class Text_Component :public Texture2D {
public:
	Text_Component();
	bool load_text_font_fromfile(SDL_Renderer* m1GAME_SCREEN, TTF_Font** gFont, std::string textureText, SDL_Color textcolor);
private:





};