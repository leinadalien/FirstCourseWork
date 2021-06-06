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
}
void Enemy::update(float time, float& offsetX, float& offsetY) {
	Entity::update(time, offsetX, offsetY);
	currentFrame += time * 0.005;
	if (currentFrame > 2) {
		currentFrame -= 2;
	}
	if (life) {
		sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, 16, 16));
	}
	else {
		sprite.setTextureRect(IntRect(58, 0, 16, 16));
	}
}
void Enemy::IsMarioBeside(int x) {
	if (abs(x - rect.left) < 1100) {
		passive = false;
		if (direction) {
			dx = 0.15;
		}
		else {
			dx = -0.15;
		}
	}
}