#include "Tile.h"

Tile::Tile()
{
	_attribs = new TAttribs(EMPTY);
	_attribs->pos.x = _attribs->pos.y = _attribs->pos.z = 0;
	_attribs->tile = ' ';
}

Tile::Tile(uint x, uint y, uint z, char tile, TTYPE type, ETYPE etype)
{
	switch (type) {
	case ENEMY:
		_attribs = new EnemyAttribs(tile, etype);
		break;
	case PLAYER:
		_attribs = new PlayerAttribs(tile);
		break;
	default:
		_attribs = new TAttribs(tile);
		break;
	}
}

Tile::~Tile()
{
	delete _attribs;
	SDL_DestroyTexture(_texture);
}

uint Tile::X()
{
	return _attribs->pos.x;
}

uint Tile::Y()
{
	return _attribs->pos.y;
}

uint Tile::Z()
{
	return _attribs->pos.z;
}

char Tile::tile()
{
	return _attribs->tile;
}

SDL_Texture* Tile::Texture()
{
	return _texture;
}

