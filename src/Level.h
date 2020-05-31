#pragma once
#include <vector>

#include "Cell.h"

using namespace std;



class Level
{
public:
	Level(uint rows = 20, uint columns = 20, uint height = 5);
	~Level();

	uint Length();
	uint Width();
	uint Height();

	void setCellWidth(uint w);
	void setCellHeight(uint h);
	void incCellWidth(uint w);
	void incCellHeight(uint h);
	void decCellWidth(uint w);
	void decCellHeight(uint h);

	void addColumns(uint n);
	void addRows(uint n);
	void addGrids(uint n);

	shared_ptr<Cell> getCell(uint x, uint y, uint z);
private:
	vector<vector<vector<shared_ptr<Cell>>>> _cells;
	uint _cellWidth;
	uint _cellHeight;
};

