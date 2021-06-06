#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Mushroom.h"
#include <fstream>

using namespace sf;

int** loadLevel(char* fileName, int& H, int& W) {
	std::ifstream fin(fileName);
	int** LevelMap = nullptr;
	if (fin.is_open()) {
		fin >> H >> W;
		LevelMap = new int* [H];
		for (int i = 0; i < H; i++) {
			LevelMap[i] = new int[W];
			for (int j = 0; j < W; j++) {
				fin >> LevelMap[i][j];
			}
		}
		fin.close();
	}
	return LevelMap;
}
void Draw(RenderWindow& window, Player& Mario, int countOfEnemies, Enemy* Enemies, int** TileMap, float& offsetX, float& offsetY, Sprite& tile, int SurpriseBoxCurrentFrame) {
	int offsetBlockY = 0;
	window.clear(Color(107, 140, 255));
	for (int i = offsetY / 64; i < (offsetY + 900) / 64; i++) {
		for (int j = offsetX / 64; j < (offsetX + 1600) / 64; j++)
		{
			switch (TileMap[i][j])
			{
			case 1:
				tile.setTextureRect(IntRect(16 * 2, 16 * 5, 16, 16));
				break;
			case 2:
				tile.setTextureRect(IntRect(16 * 1, 16 * 5, 16, 16));
				break;
			case 3:
				tile.setTextureRect(IntRect(16 * 0, 16 * 7, 16, 16));
				break;
			case 4:
				tile.setTextureRect(IntRect(16 * (int)SurpriseBoxCurrentFrame, 16 * 3, 16, 16));
				break;
			case 5:
				tile.setTextureRect(IntRect(16 * 0, 16 * 2, 16, 16));
				break;
			case 6:
				tile.setTextureRect(IntRect(16 * 5, 16 * 3, 16, 16));
				break;
			case 7:
				tile.setTextureRect(IntRect(16 * 0, 16 * 4, 16, 16));
				break;
			case 8:
				tile.setTextureRect(IntRect(16 * 0, 16 * 5, 16, 16));
				break;
			case 9:
				tile.setTextureRect(IntRect(16 * 4, 16 * 0, 16, 16));
				break;
			case 10:
				tile.setTextureRect(IntRect(16 * 4, 16 * 3, 16, 16));
				break;
			case 11:
				tile.setTextureRect(IntRect(16 * 8, 16 * 3, 16, 16));
				break;
			case 12:
				tile.setTextureRect(IntRect(16 * 7, 16 * 4, 16, 16));
				break;
			case 13:
				tile.setTextureRect(IntRect(16 * 8, 16 * 4, 16, 16));
				break;
			case 14:
				tile.setTextureRect(IntRect(16 * 9, 16 * 4, 16, 16));
				break;
			case 15:
				tile.setTextureRect(IntRect(16 * 7, 16 * 5, 16, 16));
				break;
			case 16:
				tile.setTextureRect(IntRect(16 * 8, 16 * 5, 16, 16));
				break;
			case 17:
				tile.setTextureRect(IntRect(16 * 9, 16 * 5, 16, 16));
				break;
			case 18:
				tile.setTextureRect(IntRect(16 * 10, 16 * 5, 16, 16));
				break;
			case 19:
				tile.setTextureRect(IntRect(16 * 11, 16 * 5, 16, 16));
				break;
			case 20:
				tile.setTextureRect(IntRect(16 * 6, 16 * 2, 16, 16));
				break;
			case 21:
				tile.setTextureRect(IntRect(16 * 7, 16 * 2, 16, 16));
				break;
			case 22:
				tile.setTextureRect(IntRect(16 * 6, 16 * 3, 16, 16));
				break;
			case 23:
				tile.setTextureRect(IntRect(16 * 7, 16 * 3, 16, 16));
				break;
			case 24:
				tile.setTextureRect(IntRect(16 * 4, 16 * 4, 16, 16));
				break;
			case 25:
				tile.setTextureRect(IntRect(16 * 5, 16 * 4, 16, 16));
				break;
			case 26:
				tile.setTextureRect(IntRect(16 * 4, 16 * 5, 16, 16));
				break;
			case 27:
				tile.setTextureRect(IntRect(16 * 5, 16 * 5, 16, 16));
				break;
			case 28:
				tile.setTextureRect(IntRect(16 * 6, 16 * 4, 16, 16));
				break;
			case 29:
				tile.setTextureRect(IntRect(16 * 6, 16 * 5, 16, 16));
				break;
			case 30:
				tile.setTextureRect(IntRect(16 * 5, 16 * 2, 16, 16));
				break;
			case 31:
				tile.setTextureRect(IntRect(16 * 5, 16 * 1, 16, 16));
				break;
			case 32:
				tile.setTextureRect(IntRect(16 * 4, 16 * 6, 16, 16));
				break;
			case 33:
				tile.setTextureRect(IntRect(16 * 6, 16 * 6, 16, 16));
				break;
			case 34:
				tile.setTextureRect(IntRect(16 * 5, 16 * 6, 16, 16));
				break;
			case 35:
				tile.setTextureRect(IntRect(16 * 4, 16 * 7, 16, 16));
				break;
			case 36:
				tile.setTextureRect(IntRect(16 * 6, 16 * 7, 16, 16));
				break;
			case 37:
				tile.setTextureRect(IntRect(16 * 5, 16 * 7, 16, 16));
				break;
			case 38:
				tile.setTextureRect(IntRect(16 * 0, 16 * 0, 16, 16));
				break;
			case 39:
				tile.setTextureRect(IntRect(16 * 9, 16 * 3, 16, 16));
				break;
			case 40:
				tile.setTextureRect(IntRect(16 * 10, 16 * 3, 16, 16));
				break;
			case 41:
				tile.setTextureRect(IntRect(16 * 11, 16 * 3, 16, 16));
				break;
			case 42:
				tile.setTextureRect(IntRect(16 * 12, 16 * 3, 16, 16));
				break;
			case 43:
				tile.setTextureRect(IntRect(16 * 10, 16 * 4, 16, 16));
				break;
			case 44:
				tile.setTextureRect(IntRect(16 * 11, 16 * 4, 16, 16));
				break;
			case 45:
				tile.setTextureRect(IntRect(16 * 12, 16 * 4, 16, 16));
				break;
			default:
				break;
			}
			if ((TileMap[i][j] == 0) || TileMap[i][j] == -1) continue;
			if (TileMap[i][j] == 2 || TileMap[i][j] == 4 || TileMap[i][j] == 1) {
				if ((i + 1) * 64 < Mario.rect.top && (i + 2) * 64 > Mario.rect.top && (j - 1) * 64 < Mario.rect.left && (j + 1) * 64 > Mario.rect.left) {
					if (Mario.dy > 0) {
						if (Mario.rect.top > (i + 1) * 64 && Mario.rect.top < (i + 1) * 64 + 16) {
							offsetBlockY = (Mario.rect.top - (i + 1) * 64) * 2;
						}

						if (Mario.rect.top > (i + 1) * 64 + 16 && Mario.rect.top < (i + 2) * 64) {
							if (TileMap[i][j] == 4) {
								TileMap[i][j] = 10;
								if (i == 9 && j == 22) {
								}
							}
							offsetBlockY = ((i + 2) * 64 - Mario.rect.top);
						}
					}
				}
			}
			tile.setPosition(j * 64 - offsetX, i * 64 - offsetY - offsetBlockY);
			offsetBlockY = 0;
			window.draw(tile);
		}
	}
	window.draw(Mario.sprite);
	for (int i = 0; i < countOfEnemies; i++) {
		if (Enemies[i].rect.left  > offsetX - 64 && Enemies[i].rect.left < offsetX + 1664) {
			window.draw(Enemies[i].sprite);
		}
	}
	window.display();
}
int main()
{
	RenderWindow window(VideoMode(1600, 900), "Mario", Style::Close);
	float offsetX = 64, offsetY = 0;
	float offsetBlockY = 0;
	int H, W;
	int** TileMap;
	char fileName[] = "World1-1.txt";
	TileMap = loadLevel(fileName, H, W);
	Texture tileSet;
	tileSet.loadFromFile("Mario_Tileset.png");
	Texture worldTileSet;
	worldTileSet.loadFromFile("Overworld_tileset.png");
	Player Mario(tileSet, TileMap, 7 * 64, 9 * 64);


	Enemy* Enemies = new Enemy[16];
	Enemies[0] = Enemy(tileSet, TileMap, 23 * 64, 13 * 64, false);
	Enemies[1] = Enemy(tileSet, TileMap, 41 * 64, 13 * 64, false);
	Enemies[2] = Enemy(tileSet, TileMap, 52 * 64, 13 * 64, true);
	Enemies[3] = Enemy(tileSet, TileMap, 54 * 64, 13 * 64, false);
	Enemies[4] = Enemy(tileSet, TileMap, 81 * 64, 5 * 64, false);
	Enemies[5] = Enemy(tileSet, TileMap, 83 * 64, 5 * 64, false);
	Enemies[6] = Enemy(tileSet, TileMap, 98 * 64, 13 * 64, false);
	Enemies[7] = Enemy(tileSet, TileMap, 100 * 64, 13 * 64, false);
	Enemies[8] = Enemy(tileSet, TileMap, 115 * 64, 13 * 64, false);
	Enemies[9] = Enemy(tileSet, TileMap, 117 * 64, 13 * 64, false);
	Enemies[10] = Enemy(tileSet, TileMap, 125 * 64, 13 * 64, false);
	Enemies[11] = Enemy(tileSet, TileMap, 127 * 64, 13 * 64, false);
	Enemies[12] = Enemy(tileSet, TileMap, 129 * 64, 13 * 64, false);
	Enemies[13] = Enemy(tileSet, TileMap, 131 * 64, 13 * 64, false);
	Enemies[14] = Enemy(tileSet, TileMap, 175 * 64, 13 * 64, false);
	Enemies[15] = Enemy(tileSet, TileMap, 177 * 64, 13 * 64, false);


	Sprite tile(worldTileSet);
	Sprite healthtile(tileSet);
	healthtile.setTextureRect(IntRect(231, 144, 16, 16));
	healthtile.setScale(4, 4);
	tile.setScale(4, 4);
	float SurpriseBoxCurrentFrame = 0;
	bool BlockJump = false;
	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1000;
		if (time > 20) {
			time = 20;
		}

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
			Mario.dx = -0.4;
			Mario.direction = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
			Mario.dx = 0.4;
			Mario.direction = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
			if (Mario.onGround) {
				Mario.dy = -1.5;
				Mario.onGround = false;
			}
		}
		Mario.update(time, offsetX, offsetY);
		for (int i = 0; i < 16; i++) {
			Enemies[i].update(time, offsetX, offsetY);
			if (Enemies[i].passive) {
				Enemies[i].IsMarioBeside(Mario.rect.left);
			}
		}
		
		
		SurpriseBoxCurrentFrame += time * 0.005;
		if (SurpriseBoxCurrentFrame > 4) {
			SurpriseBoxCurrentFrame -= 4;
		}
		if (Mario.rect.top >= 15 * 64) {
			Mario.healthCount--;
			Mario.rect.left = 7 * 64;
			Mario.rect.top = 9 * 64;
			offsetX = 0;
			offsetY = 0;
		}
		for (int i = 0; i < 16; i++) {
			if (!Mario.TouchEnemy(Enemies[i], offsetX, offsetY)) {
				return 0;
			}
		}
		
		if (Mario.rect.left > 864 && Mario.rect.left < W * 64 - 864) {
			offsetX = Mario.rect.left - 800;
		}
		Draw(window, Mario, 16, Enemies, TileMap, offsetX, offsetY, tile, SurpriseBoxCurrentFrame);
	}

	return 0;
}