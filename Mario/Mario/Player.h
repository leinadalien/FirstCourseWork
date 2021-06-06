#pragma once
#include "Entity.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Player : public Entity {
public:
	float prevdx;
	float currentFrame;
	int healthCount;
	Player(Texture& image, int** TileMap, int x, int y);
	void SetLevel(int** TileMap);
	void update(float time, float& offsetX, float& offsetY) override;
	bool TouchEnemy(Enemy& enemy, float& offsetX, float& offsetY);
};