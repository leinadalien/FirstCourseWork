#include "Entity.h"
using namespace sf;
Entity::Entity() {
	sprite.setScale(4, 4);
	rect = FloatRect(0, 0, 56, 64);
	dx = 0;
	dy = 0.1;
	onGround = false;
	TileMap = nullptr;
	direction = true;
}
Entity::Entity(Texture& image, int** TileMap, int x, int y, bool direction) {
	sprite.setTexture(image);
	sprite.setScale(4, 4);
	rect = FloatRect(x, y, 56, 64);
	dx = 0;
	dy = 0.1;
	onGround = false;
	this->TileMap = TileMap;
	this->direction = direction;
}
void Entity::Collision(int num)
{

	for (int i = rect.top / 64; i < (rect.top + rect.height) / 64; i++) {
		for (int j = rect.left / 64; j < (rect.left + rect.width) / 64; j++) {
			if ((TileMap[i][j] == -1) || (TileMap[i][j] == 1) || (TileMap[i][j] == 2) || (TileMap[i][j] == 3) || (TileMap[i][j] == 4) || (TileMap[i][j] == 6) || (TileMap[i][j] == 10) || (TileMap[i][j] > 19 && TileMap[i][j] < 28)) {
				if (dy > 0 && num == 1) {
					rect.top = i * 64 - rect.height;
					dy = 0;

					onGround = true;
				}
				if (dy < 0 && num == 1) {
					rect.top = (i + 1) * 64;
					dy = 0;
				}
				if (dx > 0 && num == 0)
				{
					rect.left = j * 64 - rect.width;
					dx *= -1;
					direction = false;
				}
				else if (dx < 0 && num == 0)
				{
					rect.left = (j + 1) * 64;
					dx *= -1;
					direction = true;
				}
			}
		}
	}
}
void Entity::update(float time, float& offsetX, float& offsetY) {
	rect.left += dx * time;
	Collision(0);
	if (!onGround) {
		dy += 0.004 * time;
	}
	rect.top += dy * time;
	onGround = false;
	Collision(1);
	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
}