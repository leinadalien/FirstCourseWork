#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Enemy : public Entity {
public:
	float currentFrame;
	bool life;
	bool passive;
	Enemy();
	Enemy(Texture& image, int** TileMap, int x, int y, bool direction);
	void update(float time, float& offsetX, float& offsetY, float x);
	void Collision(int num) override;
};

