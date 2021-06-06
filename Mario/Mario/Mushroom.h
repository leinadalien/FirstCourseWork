#pragma once
#include "Entity.h"
class Mushroom : public Entity
{
public:
	Mushroom();
	Mushroom(Texture& image, int** TileMap, int x, int y, bool direction);
};

