#include "Mushroom.h"
using namespace sf;
Mushroom::Mushroom() : Entity() {
	dx = 0;
	sprite.setTextureRect(IntRect(16 * 5, 16 * 0, 16, 16));
	life = false;
}
void Mushroom::Collision(int num) {
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
Mushroom::Mushroom(Texture& image, int** TileMap, int x, int y, bool direction) : Entity(image, TileMap, x, y, direction) {
	dx = 0;
	life = false;
}
void Mushroom::update(float time, float& offsetX, float& offsetY) {
	if (life) {
		
		Entity::update(time, offsetX, offsetY);
		dx = direction ? 0.25 : -0.25;
		sprite.setTextureRect(IntRect(16 * 4, 16 * 0, 16, 16));
	}
	else {
		dx = 0;
		sprite.setTextureRect(IntRect(16 * 5, 16 * 0, 16, 16));
	}
}
