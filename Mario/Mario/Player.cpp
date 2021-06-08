#include "Player.h"
using namespace sf;
Player::Player() : Entity(){
	money = 0;
	score = 0;
	playerTileset.loadFromFile("Player_skin_tileset.png");
	sprite.setTexture(playerTileset);
	prevdx = dx = 0;
	currentFrame = 0;
	healthCount = 3;
	skinID = 0;
	rect.top = 0;
	rect.left = 0;
	life = true;
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
			sprite.setTextureRect(IntRect(6 * 16, skinID * 16, 16, 16 * (1 + skinID % 2)));
		}
		else {
			sprite.setTextureRect(IntRect(7 * 16, skinID * 16, -16, 16 * (1 + skinID % 2)));
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
			sprite.setTextureRect(IntRect(2 * 16 + 16 * int(currentFrame), skinID* 16, 16, 16 * (1 + skinID % 2)));
		}
		else if (dx < 0) {
			sprite.setTextureRect(IntRect(3 * 16 + 16 * int(currentFrame), skinID * 16, -16, 16 * (1 + skinID % 2)));
		}
		else if (dx == 0) {
			if (direction) {
				sprite.setTextureRect(IntRect(0, skinID * 16, 16, 16 * (1 + skinID % 2)));
			}
			else {
				sprite.setTextureRect(IntRect(16, skinID * 16, -16, 16 * (1 + skinID % 2)));
			}
		}
	}
	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	prevdx = dx;
	dx = 0;
}
void Player::TouchEnemy(Enemy& enemy) {
	if (rect.intersects(enemy.rect)) {
		
		if (enemy.life) {
			if (dy > 0) {
				score += 100;
				enemy.dx = 0;
				dy = -0.8;		
				enemy.life = false;
			}
			else {
				if (skinID % 2 == 0) {
					life = false;
					healthCount--;
				}
				else {
					skinID--;
					rect.height /= 2;
					dy = -1;
				}
			}
		}

	}
}
void Player::TakeMushroom(Mushroom& mushroom, float& offsetX, float& offsetY) {
	if (mushroom.life && rect.intersects(mushroom.rect)) {
		score += 1000;
		skinID += 1 - skinID % 2;
		rect = rect = FloatRect(rect.left, rect.top - 64, 56, 128);
		mushroom.life = false;
	}
}