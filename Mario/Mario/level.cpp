#include "Level.h"
#include <fstream>
#include <string>
using namespace sf;
Level::Level(char* fileName, float startX, float startY) {
	Healths = 3;
	pixelFont.loadFromFile("font.ttf");
	score.setFont(pixelFont);
	score.setCharacterSize(40);
	score.setPosition(20, 20);
	money.setFont(pixelFont);
	money.setCharacterSize(40);
	money.setPosition(420, 20);
	lives.setFont(pixelFont);
	lives.setCharacterSize(40);
	lives.setPosition(820, 20);
	timetext.setFont(pixelFont);
	timetext.setCharacterSize(40);
	timetext.setPosition(1220, 20);
	this->fileName = fileName;
	offsetX = 64;
	tileSet.loadFromFile("Mario_Tileset.png");
	worldTileSet.loadFromFile("Overworld_tileset.png");
	std::ifstream fin(fileName);
	levelMap = nullptr;
	if (fin.is_open()) {
		fin >> H >> W;
		levelMap = new int* [H];
		for (int i = 0; i < H; i++) {
			levelMap[i] = new int[W];
			for (int j = 0; j < W; j++) {
				fin >> levelMap[i][j];
			}
		}
		fin >> countOfEnemies;
		enemies = new Enemy[countOfEnemies];
		int x, y;
		bool direction;
		for (int i = 0; i < countOfEnemies; i++) {
			fin >> x >> y >> direction;
			enemies[i] = Enemy(tileSet, levelMap, x * 64, y * 64, direction);
		}
		fin >> countOfBonuses;
		if (countOfBonuses > 0) {
			mushrooms = new Mushroom[countOfBonuses];
			for (int i = 0; i < countOfBonuses; i++) {
				fin >> x >> y >> direction;
				mushrooms[i] = Mushroom(worldTileSet, levelMap, x * 64, y * 64, direction);

			}
		}
		fin.close();
	}
	Mario.TileMap = levelMap;
	Mario.rect.left = startX * 64;
	Mario.rect.top = startY * 64;
	tile.setTexture(worldTileSet);
	tile.setScale(4, 4);
	bonusCurrentFrame = 0;
}
void Level::Draw(RenderWindow& window) {
	int offsetBlockY = 0;
	window.clear(Color(107, 140, 255));
	for (int i = offsetY / 64; i < (offsetY + 900) / 64; i++) {
		for (int j = offsetX / 64; j < (offsetX + 1600) / 64; j++) {
			switch (levelMap[i][j])
			{
			case 0:
				tile.setTextureRect(IntRect(16 * 2, 16 * 5, 16, 16));
				break;
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
				tile.setTextureRect(IntRect(16 * (int)bonusCurrentFrame, 16 * 3, 16, 16));
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
				continue;
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
			case 46:
				tile.setTextureRect(IntRect(16 * 4, 16 * 3, 16, 16));
				break;
			default:
				break;
			}
			
			if (levelMap[i][j] == 2 || levelMap[i][j] == 4 || levelMap[i][j] == 1 || (levelMap[i][j] == 46)) {
				if ((i + 1) * 64 < Mario.rect.top && (i + 2) * 64 > Mario.rect.top && j * 64 - 30 < Mario.rect.left + 32 && (j + 1) * 64 + 30 > Mario.rect.left + 32) {
					if (Mario.dy > 0) {
						if (Mario.rect.top > (i + 1) * 64 && Mario.rect.top < (i + 1) * 64 + 16 && Mario.dy < 0.5) {
							offsetBlockY = (Mario.rect.top - (i + 1) * 64) * 2;
						}
						if (Mario.rect.top > (i + 1) * 64 + 16 && Mario.rect.top < (i + 2) * 64 && Mario.dy < 1 && Mario.dy > 0.4) {
							if (levelMap[i][j] == 4) {

								levelMap[i][j] = 46;
								bool isMushroom = false;
								int k;
								for (k = 0; k < countOfBonuses; k++) {
									if (mushrooms[k].rect.top / 64 + 1 == i && mushrooms[k].rect.left / 64 == j) {
										isMushroom = true;
										break;
									}
								}
								if (isMushroom) {
									mushrooms[k].life = true;
								}
								else {
									Mario.score += 200;
									Mario.money++;
								}
								
							}
							else if (Mario.skinID % 2 == 1 && levelMap[i][j] != 46 ) {
								levelMap[i][j] = 0;
							}
							offsetBlockY = ((i + 2) * 64 - Mario.rect.top);
						}
						
						if (offsetBlockY < 0.5 && levelMap[i][j] == 46) {
							levelMap[i][j] = 10;
						}
					}
				}
			}
			if ((levelMap[i][j] == 0) || levelMap[i][j] == -1) continue;
			tile.setPosition(j * 64 - offsetX, i * 64 - offsetY - offsetBlockY);
			offsetBlockY = 0;
			window.draw(tile);
		}
	}
	window.draw(Mario.sprite);
	for (int i = 0; i < countOfEnemies; i++) {
		if (enemies[i].rect.left > offsetX - 64 && enemies[i].rect.left < offsetX + 1664) {
			window.draw(enemies[i].sprite);
		}
	}
	for (int i = 0; i < countOfBonuses; i++) {
		if (mushrooms[i].rect.left > offsetX - 64 && mushrooms[i].rect.left < offsetX + 1664) {
			window.draw(mushrooms[i].sprite);
		}
	}
	window.draw(score);
	window.draw(lives);
	window.draw(money);
	window.draw(timetext);
	window.display();
}
void Level::Update(float time) {
	timeLeft -= time;
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
	for (int i = 0; i < countOfEnemies; i++) {
		enemies[i].update(time, offsetX, offsetY, Mario.rect.left);
	}


	bonusCurrentFrame += time * 0.005;
	if (bonusCurrentFrame > 4) {
		bonusCurrentFrame -= 4;
	}
	if (Mario.rect.top >= (15 - Mario.skinID % 2) * 64) {
		Mario.life = false;
		Mario.healthCount--;
		Mario.skinID -= Mario.skinID % 2;
		Mario.rect.height = 64;
	}
	for (int i = 0; i < 16; i++) {
		Mario.TouchEnemy(enemies[i]);
	}

	if (Mario.rect.left > 864 && Mario.rect.left < W * 64 - 864) {
		offsetX = Mario.rect.left - 800;
	}
	for (int i = 0; i < countOfBonuses; i++) {
		mushrooms[i].update(time, offsetX, offsetY);
		Mario.TakeMushroom(mushrooms[i], offsetX, offsetY);
	}
	
	score.setString("Score " + std::to_string(Mario.score));
	lives.setString("Lives " + std::to_string(Mario.healthCount));
	money.setString("Coins " + std::to_string(Mario.money));
	timetext.setString("Time " + std::to_string((int)(timeLeft/1000)));
	if (Mario.rect.left > 201 * 64) {
		won = true;
	}
}
void Level::Start(float startX, float startY) {
	
	offsetX = 64;
	offsetY = 0;
	std::ifstream fin(fileName);
	levelMap = nullptr;
	if (fin.is_open()) {
		fin >> H >> W;
		levelMap = new int* [H];
		for (int i = 0; i < H; i++) {
			levelMap[i] = new int[W];
			for (int j = 0; j < W; j++) {
				fin >> levelMap[i][j];
			}
		}
		fin >> countOfEnemies;
		enemies = new Enemy[countOfEnemies];
		int x, y;
		bool direction;
		for (int i = 0; i < countOfEnemies; i++) {
			fin >> x >> y >> direction;
			enemies[i] = Enemy(tileSet, levelMap, x * 64, y * 64, direction);
		}
		fin >> countOfBonuses;
		if (countOfBonuses > 0) {
			mushrooms = new Mushroom[countOfBonuses];
			for (int i = 0; i < countOfBonuses; i++) {
				fin >> x >> y >> direction;
				mushrooms[i] = Mushroom(worldTileSet, levelMap, x * 64, y * 64, direction);

			}
		}
		fin.close();
		Mario.rect.left = startX;
		Mario.rect.top = startY;
		Mario.life = true;
	}
	Mario.TileMap = levelMap;
}
void Level::gameOver(RenderWindow& window) {
	window.clear(sf::Color::Black);
	score.setCharacterSize(50); 
	score.setPosition(550, 500);
	score.setString("Score " + std::to_string(Mario.score));
	window.draw(score);
	score.setCharacterSize(150);
	score.setPosition(250, 350);
	score.setString("Game Over");
	window.draw(score);
	window.display();
}
void Level::Won(RenderWindow& window) {
	window.clear(sf::Color::Black);
	score.setCharacterSize(50);
	score.setPosition(550, 500);
	score.setString("Score " + std::to_string(Mario.score));
	window.draw(score);
	score.setCharacterSize(150);
	score.setPosition(260, 350);
	score.setString("You won!");
	window.draw(score);
	score.setCharacterSize(25);
	score.setPosition(650, 700);
	score.setString("Coming soon?");
	window.draw(score);
	window.display();
}