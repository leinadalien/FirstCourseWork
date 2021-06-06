#include "Player.h"
using namespace sf;
	Player::Player(Texture& image, int** TileMap, int x, int y) : Entity(image, TileMap, x, y, true){
		prevdx = dx = 0; 
		currentFrame = 0;
		healthCount = 3;
	}
	void Player::SetLevel(int** TileMap) {
		this->TileMap = TileMap;
	}
	void Player::update(float time, float& offsetX, float& offsetY) {
		rect.left += dx * time;
		Collision(0);
		if (!onGround) {
			dy += 0.004 * time;

			if (direction) {
				sprite.setTextureRect(IntRect(231, 144, 16, 16));
			}
			else {
				sprite.setTextureRect(IntRect(246, 144, -16, 16));
			}
		}
		rect.top += dy * time;
		onGround = false;
		Collision(1);
		if (onGround) {
			currentFrame += time * 0.02;
			if (currentFrame > 3) {
				currentFrame -= 3;
			}
			if (dx > 0) {
				sprite.setTextureRect(IntRect(110 + 31 * int(currentFrame), 144, 16, 16));
			}
			else if (dx < 0) {
				sprite.setTextureRect(IntRect(126 + 31 * int(currentFrame), 144, -16, 16));
			}
			else if (dx == 0) {
				if (direction) {
					sprite.setTextureRect(IntRect(79, 144, 16, 16));
				}
				else {
					sprite.setTextureRect(IntRect(95, 144, -16, 16));
				}
			}
		}
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
		prevdx = dx;
		dx = 0;
	}
	bool Player::TouchEnemy(Enemy& enemy, float& offsetX, float& offsetY) {
		if (rect.intersects(enemy.rect)) {
			if (enemy.life) {
				if (dy > 0) {
					enemy.dx = 0;
					dy = -0.8;
					enemy.life = false;
				}
				else if (healthCount > 1) {
					healthCount--;
					rect.left = 7 * 64;
					rect.top = 9 * 64;
					offsetX = 64;
					offsetY = 0;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}