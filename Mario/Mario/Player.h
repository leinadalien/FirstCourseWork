#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "Mushroom.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Player : public Entity {
public:
	int money;
	int score;
	Texture playerTileset;
	int skinID;
	float prevdx;
	float currentFrame;
	int healthCount;
	bool life;
	Player();
	Player(int** TileMap, int x, int y);
	void SetLevel(int** TileMap);
	void update(float time, float& offsetX, float& offsetY) override;
	void TouchEnemy(Enemy& enemy);
	void TakeMushroom(Mushroom& mushroom, float& offsetX, float& offsetY);
};