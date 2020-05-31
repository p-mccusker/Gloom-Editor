#include "Level.h"

Level::Level(uint rows, uint columns, uint height)
{
	//Default width and height of 40 pixels for each tile
	_cellHeight = _cellWidth = 40;

	for (int i = 0; i < height; i++) {
		vector<vector<shared_ptr<Cell>>> grid;
		uint yCoord = 0;
		for (int j = 0; j < rows; j++) {
			uint xCoord = 0;
			vector<shared_ptr<Cell>> line;
			for (int k = 0; k < columns; k++) {
				line.push_back(make_shared<Cell>(k, j, i, _cellHeight, 
												 _cellWidth, xCoord, yCoord));
				xCoord += _cellWidth;
			}
			grid.push_back(line);
			yCoord += _cellHeight;
		}
		_cells.push_back(grid);
	}
}

Level::~Level()
{

}
/// <summary>
/// Number of columns, x-coordinate
/// </summary>
/// <returns></returns>
uint Level::Width()
{
	return _cells[0][0].size();
}
/// <summary>
/// Number of rows, y-coordinate
/// </summary>
/// <returns></returns>
uint Level::Length()
{
	return _cells[0].size();
}
/// <summary>
/// Number of grids, z-coordinate
/// </summary>
/// <returns></returns>
uint Level::Height()
{
	return _cells.size();
}

/// <summary>
/// Sets the width of each cell in the level in pixels
/// </summary>
/// <param name="w"></param>
void Level::setCellWidth(uint w)
{
	_cellWidth = w;
	for (auto& grid : _cells) {
		for (auto& row : grid) {
			for (auto& cell : row) {
				cell->setWidth(_cellWidth);
			}
		}
	}
	
}
/// <summary>
/// Sets the height of each cell in the level in pixels
/// </summary>
/// <param name="w"></param>
void Level::setCellHeight(uint h)
{
	_cellHeight = h;
	for (auto& grid : _cells) {
		for (auto& row : grid) {
			for (auto& cell : row) {
				cell->setHeight(_cellHeight);
			}
		}
	}	
}
/// <summary>
/// increases the width of all cells by w
/// </summary>
/// <param name="w"></param>
void Level::incCellWidth(uint w)
{
	_cellWidth += w;
	for (auto& grid : _cells) {
		for (auto& row : grid) {
			for (auto& cell : row) {
				cell->setWidth(_cellWidth);
			}
		}
	}
}
/// <summary>
/// increases the height of all cells by h
/// </summary>
/// <param name="w"></param>
void Level::incCellHeight(uint h)
{
	_cellHeight += h;
	for (auto& grid : _cells) {
		for (auto& row : grid) {
			for (auto& cell : row) {
				cell->setHeight(_cellHeight);
			}
		}
	}
}
/// <summary>
/// decreases the width of all cells by w
/// </summary>
/// <param name="w"></param>
void Level::decCellWidth(uint w)
{
	_cellWidth -= w;
	for (auto& grid : _cells) {
		for (auto& row : grid) {
			for (auto& cell : row) {
				cell->setWidth(_cellWidth);
			}
		}
	}
}
/// <summary>
/// decreases the height of all cells by h
/// </summary>
/// <param name="w"></param>
void Level::decCellHeight(uint h)
{
	_cellHeight -= h;
	for (auto& grid : _cells) {
		for (auto& row : grid) {
			for (auto& cell : row) {
				cell->setHeight(_cellHeight);
			}
		}
	}
}

void Level::addColumns(uint n)
{
	const uint width = Width();

	for (uint z = 0; z < Height(); z++) {
		for (uint y = 0; y < Length(); y++) {
			for (uint x = width; x < width+n; x++) {
				_cells[z][y].push_back(make_shared<Cell>(x,y,z));
			}
		}
	}
}

void Level::addRows(uint n) {
	const uint length = Length();

	for (uint z = 0; z < Height(); z++) {
		for (uint y = length; y < length+n; y++) {
			vector<shared_ptr<Cell>> line;
			for (uint x = 0; x < Width(); x++) {
				line.push_back(make_shared<Cell>(x, y, z));
			}
			_cells[z].push_back(line);
		}
	}
}

void Level::addGrids(uint n) {
	// May need to add ability to decide where to place grid in level
	const uint height = Height();

	for (uint z = height; z < height + n; z++) {
		vector<vector<shared_ptr<Cell>>> grid;
		for (uint y = 0; y < Length(); y++) {
			vector<shared_ptr<Cell>> line;
			for (uint x = Width(); x < Width() + n; x++) {
				line.push_back(make_shared<Cell>(x, y, z));
			}
			grid.push_back(line);
		}
		_cells.push_back(grid);
	}
}

shared_ptr<Cell> Level::getCell(uint x, uint y, uint z)
{
	return _cells[z][y][x];
}
