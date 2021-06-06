#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Entity
{
public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	bool direction;
	bool onGround;
	int** TileMap;
	Entity();
	Entity(Texture& image, int** TileMap, int x, int y, bool direction);
	virtual void update(float time, float& offsetX, float& offsetY);
	void Collision(int num);
};



