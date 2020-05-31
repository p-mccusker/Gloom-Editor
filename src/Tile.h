#pragma once
#include <string>

#include "../../include/SDL.h"

#include "Lists.h"
#include "FontTexCreator.h"

enum TTYPE { NULL_TILE, EMPTY, FLOOR, STAIR, DOOR, WALL, 
			 CONTAINER, ENEMY, PLAYER  };

enum ETYPE { NULL_ENEMY, GOBLIN, HYDRA, OGRE, RAT, ROGUE};



typedef struct {
	uint x, y, z;
} Pos;

struct TAttribs {
	TAttribs(char t);
	~TAttribs() {}
	Pos pos;
	char tile;
};

TAttribs::TAttribs(char t) {
	pos.x = pos.y = pos.z = 0;
	tile = t;
}

struct EntityAttribs : TAttribs {
	EntityAttribs(char t);
	~EntityAttribs() { }
	std::string name;
	uint health,
		level,
		damage,
		defense;
};

EntityAttribs::EntityAttribs(char t) :TAttribs(t) {
	health = 0;
	level = 0;
	damage = 0;
	defense = 0;
}

struct EnemyAttribs : EntityAttribs {
	EnemyAttribs(char t, ETYPE type);
	~EnemyAttribs() { }
	uint xpWorth;
};


EnemyAttribs::EnemyAttribs(char t, ETYPE type) :EntityAttribs(t) {
	switch (type) {
	case RAT:
		name = 'Rat';
		health = 10;
		level = 1;
		damage = 3;
		defense = 0;
		xpWorth = 5;
		break;
	case ROGUE:
		name = Lists::randomName(HUMAN);
		health = 20;
		level = 3;
		damage = 7;
		defense = 2;
		xpWorth = 15;
		break;
	case GOBLIN:
		name = Lists::randomName(MONSTER);
		health = 15;
		level = 2;
		damage = 5;
		defense = 1;
		xpWorth = 10;
		break;
	case OGRE:
		name = Lists::randomName(MONSTER);
		health = 25;
		level = 5;
		damage = 10;
		defense = 4;
		xpWorth = 30;
		break;

	}
}

struct PlayerAttribs : EntityAttribs {
	PlayerAttribs(char t);
	uint exp;
};

PlayerAttribs::PlayerAttribs(char t) :EntityAttribs(t) {
	exp = 0;
}



class Tile
{
public:
	Tile();
	Tile(uint x, uint y, uint z, char tile, TTYPE type, ETYPE etype = NULL_ENEMY);
	~Tile();

	void setTexture(SDL_Texture* tex) { _texture = std::move(tex);  }

	uint X();
	uint Y();
	uint Z();
	char tile();
	SDL_Texture* Texture();

private:
	TAttribs* _attribs;
	SDL_Texture* _texture;
};

