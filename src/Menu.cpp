#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
	SDL_FreeSurface(_surface);
}
