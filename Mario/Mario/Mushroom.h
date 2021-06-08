#pragma once
#include "Entity.h"
class Mushroom : public Entity
{
public:
	Mushroom();
	Mushroom(Texture& image, int** TileMap, int x, int y, bool direction);
	bool life;
	void update(float time, float& offsetX, float& offsetY) override;
	void Collision(int num) override;
};

