#include "FontTexCreator.h"

FontTexCreator::FontTexCreator(const char* fontName, uint fontSize)
{
	TTF_Init();
	_font = TTF_OpenFont(fontName, fontSize);
}

FontTexCreator::~FontTexCreator()
{
	TTF_CloseFont(_font);
	TTF_Quit();
}

void FontTexCreator::changeFont(const char* fontName, uint fontSize)
{
	TTF_CloseFont(_font);
	_font = TTF_OpenFont(fontName, fontSize);
}

SDL_Texture* FontTexCreator::textureFromFont(SDL_Renderer* render, const char* message, SDL_Color fontColor)
{
	SDL_Surface* mess = TTF_RenderText_Solid(_font, message, fontColor);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(render, mess);
	SDL_FreeSurface(mess);
	return tex;
}
