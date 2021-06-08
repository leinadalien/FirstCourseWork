#include "Enemy.h"
using namespace sf;
Enemy::Enemy() : Entity(){
	currentFrame = 0;
	life = true;
	passive = true;
	dx = 0;
}
Enemy::Enemy(Texture& image, int** TileMap, int x, int y, bool direction) : Entity(image, TileMap, x, y, direction) {
	currentFrame = 0;
	life = true;
	passive = true;
	dx = 0;
	sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, 16, 16));
}
void Enemy::Collision(int num) {
	for (int i = rect.top / 64; i < (rect.top + rect.height) / 64; i++) {
		for (int j = rect.left / 64; j < (rect.left + rect.width) / 64; j++) {
			if ((i >= 0) && (j >= 0) && ((TileMap[i][j] == -1) || (TileMap[i][j] == 1) || (TileMap[i][j] == 2) || (TileMap[i][j] == 3) || (TileMap[i][j] == 4) || (TileMap[i][j] == 6) || (TileMap[i][j] == 10) || (TileMap[i][j] == 46) || (TileMap[i][j] > 19 && TileMap[i][j] < 28))) {
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
				}
				else if (dx < 0 && num == 0)
				{
					rect.left = (j + 1) * 64;
					dx *= -1;
				}
			}
		}
	}
}
void Enemy::update(float time, float& offsetX, float& offsetY, float x) {
	Entity::update(time, offsetX, offsetY);
	currentFrame += time * 0.005;
	if (currentFrame > 2) {
		currentFrame -= 2;
	}
	if (rect.top >= 15 * 64) {
		life = false;
	}
	if (life) {
		sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, 16, 16));
	}
	else {
		sprite.setTextureRect(IntRect(58, 0, 16, 16));
	}
	if (passive && abs(x - rect.left) < 1100) {
		passive = false;
		if (direction) {
			dx = 0.15;
		}
		else {
			dx = -0.15;
		}
	}
}