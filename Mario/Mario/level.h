#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include"Mushroom.h"
using namespace sf;
class Level
{
public:
	bool won = false;
	int Healths;
	Font pixelFont;
	Text score, lives, money, timetext;
	float timeLeft = 180000;
	char* fileName;
	float offsetX, offsetY;
	int H, W;
	int** levelMap;
	float bonusCurrentFrame;
	Texture tileSet;
	Texture playerTileset;
	Texture worldTileSet;
	Player Mario;
	Sprite tile;
	int countOfEnemies;
	Enemy* enemies;
	int countOfBonuses;
	Mushroom* mushrooms;
	Level();
	Level(char* fileName, float startX, float startY);
	void LoadFromFile(char* fileName);
	void Update(float time);
	void Draw(RenderWindow& window);
	void Start(float startX, float startY);
	void gameOver(RenderWindow& window);
	void Won(RenderWindow& window);
};

