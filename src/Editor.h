#pragma once
#include <vector>
#include <any>

#include "Level.h"

using namespace std;

enum DIRECTION {NORTH, SOUTH, EAST, WEST, UP, DOWN };

class Editor
{
public:
	Editor(uint wid, uint hght);
	~Editor();

	void Run();

	void Draw();

	void Help();
private:
	Level* _level;
	SDL_Window* _win;
	SDL_Renderer* _ren;
	shared_ptr<Cell> _activeCell;
	std::any* _clipboard;
	FontTexCreator* _fontTexturer;

	void Setup();
	void Copy();
	void Cut();
	void mvCursor(DIRECTION dir);
	void mvCurNorth();
	void mvCurSouth();
	void mvCurEast();
	void mvCurWest();
	void mvCurUp();
	void mvCurDown();
	bool _isRunning;
	
};

