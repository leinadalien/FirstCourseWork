#include "Mushroom.h"
using namespace sf;
Mushroom::Mushroom() : Entity() {
	dx = 0.2;
	sprite.setTextureRect(IntRect(16 * 0, 16 * 4, 16, 16));
}
Mushroom::Mushroom(Texture& image, int** TileMap, int x, int y, bool direction) : Entity(image, TileMap, x, y, direction) {
	if (direction) {
		dx = 0.2;
	}
	else {
		dx = -0.2;
	}
	sprite.setTextureRect(IntRect(16 * 0, 16 * 4, 16, 16));
}