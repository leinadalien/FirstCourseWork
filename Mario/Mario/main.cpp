#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Mushroom.h"
#include "level.h"
#include <fstream>

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(1600, 900), "Mario", Style::None);
	char fileName[] = "World1-1.txt";
	Level level(fileName, 7,9);
	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1000;
		if (time > 20) {
			time = 20;
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}
		if (level.won) {
			level.Won(window);
		}
		else {
			if (level.timeLeft > 0) {
				if (level.Mario.life) {
					level.Update(time);
					level.Draw(window);

				}
				else if (level.Mario.healthCount > 0) {
					level.Mario.score = 0;
					level.Start(7 * 64, 9 * 64);
				}
				else {
					level.gameOver(window);
				}
			}
			else {
				level.gameOver(window);
			}
		}
		
	}
	return 0;
}