#include "Cell.h"

Cell::Cell(uint xC, uint yC, uint zC, uint height, uint width, uint startX, uint startY)
{
	_tile =  std::make_shared<Tile>(xC, yC, xC, ' ', EMPTY);
	_area->h = height;
	_area->w = width;
	_area->x = startX;
	_area->y = startY;
}

Cell::Cell(const Cell& cell)
{
	auto tileData = cell._tile;
	auto rectData = cell._area;
	*_tile = *tileData;
	*_area = *rectData;
}

Cell::~Cell()
{
	delete _area;
}

uint Cell::X()
{
	return _tile->X();
}

uint Cell::Y()
{
	return _tile->Y();
}

uint Cell::Z()
{
	return _tile->Z();
}

uint Cell::Width()
{
	return _area->w;
}

uint Cell::Height()
{
	return _area->h;
}

uint Cell::EndX()
{
	return _area->x+Width();
}

uint Cell::EndY()
{
	return _area->y + Height();
}

std::shared_ptr<Tile> Cell::getTile() {
	return _tile;
}

void Cell::setX(uint x) {
	_area->x = x;
}
void Cell::setY(uint y) {
	_area->y = y;
}
void Cell::setWidth(uint w) {
	_area->w = w;
}
void Cell::setHeight(uint h) {
	_area->h = h;
}