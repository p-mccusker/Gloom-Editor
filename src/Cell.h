#pragma once
#include <memory>

#include "Tile.h"

class Cell
{
public:
	Cell(uint xC, uint yC, uint zC, 
		uint height = 40, uint width = 40,
		uint startX = 0, uint startY = 0);
	Cell(const Tile& tile);
	~Cell();

	void setX(uint x);
	void setY(uint y);
	void setWidth(uint w);
	void setHeight(uint h);

	uint X();
	uint Y();
	uint Z();
	uint Width();
	uint Height();
	uint EndX();
	uint EndY();

	std::shared_ptr<Tile> getTile();

private:
	SDL_Rect* _area;
	std::shared_ptr<Tile> _tile;
};

