#pragma once

#include "EnemyCar.h"
class car {
public:
	int xPos;
	int yPos;
	car() { xPos = 2; yPos = 16; }
	void draw();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void checkCollision(EnemyCar *EC, bool *running);
};
