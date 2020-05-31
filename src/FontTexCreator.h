#pragma once
#include <string>
#include "../../include/SDL_ttf.h"

using uint = unsigned int;

const SDL_Color WHITE { 255, 255, 255 };
const SDL_Color BLACK { 0, 0, 0 };
const SDL_Color RED { 255, 0, 0 };
const SDL_Color GREEN { 0, 255, 0 };
const SDL_Color BLUE { 0, 0, 255 };

class FontTexCreator
{
public:
	FontTexCreator(const char* fontName, uint fontSize);
	~FontTexCreator();

	void changeFont(const char* fontName, uint fontSize = 24);

	SDL_Texture* textureFromFont(SDL_Renderer* render, const char* message, SDL_Color fontColor);
private:
	TTF_Font* _font;

};

