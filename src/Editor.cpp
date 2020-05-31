#include "Editor.h"

Editor::Editor(uint wid, uint hght)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	_clipboard = nullptr;
	
	_win = SDL_CreateWindow("Gloom Editor", SDL_WINDOWPOS_CENTERED, 
							SDL_WINDOWPOS_CENTERED, wid, hght, NULL);
	_ren = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED);

	_fontTexturer = new FontTexCreator("Sans", 24);

	_level = new Level(20, 20, 5);

}

Editor::~Editor() {
	delete _clipboard;
	delete _fontTexturer;
	delete _level;
	SDL_DestroyRenderer(_ren);
	SDL_DestroyWindow(_win);
	SDL_Quit();
}

void Editor::Setup()
{
	_activeCell = _level->getCell(0,0,0);

	// Horribly inefficient
	for (uint z = 0; z < _level->Height(); z++) {
		for (uint y = 0; y < _level->Length(); y++) {
			for (uint x = 0; x < _level->Width(); x++) {
				auto Tile = _level->getCell(x, y, z)->getTile();
				SDL_Texture* tileTex = _fontTexturer->textureFromFont(_ren, (char*)Tile->tile(), WHITE);
				Tile->setTexture(tileTex);
				SDL_DestroyTexture(tileTex);
			}
		}
	}

}

void Editor::Copy()
{
}

void Editor::Cut()
{
}

void Editor::mvCursor(DIRECTION dir)
{
}

void Editor::mvCurNorth()
{
	if 
}

void Editor::mvCurSouth()
{
}

void Editor::mvCurEast()
{
}

void Editor::mvCurWest()
{
}

void Editor::mvCurUp()
{
}

void Editor::mvCurDown()
{
}

void Editor::Run()
{
	SDL_Event event;

	while (_isRunning) {
		Draw();
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYUP: {
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					mvCurNorth();
					break;
				case SDLK_DOWN:
					mvCurSouth();
					break;
				case SDLK_LEFT:
					mvCurWest();
					break;
				case SDLK_RIGHT:
					mvCurEast();
					break;
				case SDLK_LESS:
					mvCurDown();
					break;
				case SDLK_GREATER:
					mvCurUp();
					break;
				case SDLK_TAB:

					break;
				case SDLK_RETURN:

					break;
				case SDLK_QUESTION:

					break;
				case SDLK_ESCAPE:
					_isRunning = false;
					break;
				default:
					break;
				}
				break;
			}
			default:
				break;
			}
		}
		
	}
}

void Editor::Draw()
{

}
