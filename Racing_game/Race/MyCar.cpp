#include "stdafx.h"
#include "MyCar.h"

void car::draw() {
	drawPoint(xPos, yPos);
	drawPoint(xPos - 1, yPos + 1);
	drawPoint(xPos + 1, yPos + 1);
	drawPoint(xPos, yPos + 1);
	drawPoint(xPos, yPos + 2);
	drawPoint(xPos - 1, yPos + 3);
	drawPoint(xPos + 1, yPos + 3);
	drawPoint(xPos, yPos + 3);
}
void car::moveLeft() {
	if (xPos == 5) {
		xPos = 2;
	}
	else if (xPos == 8) { xPos = 5; };
}
void car::moveRight() {
	if (xPos == 2) {
		xPos = 5;
	}
	else if (xPos == 5) { xPos = 8; }
}


void car::moveUp()
{
	if (yPos < 20 && yPos>1) {
		yPos--;
	}
}

void car::moveDown()
{
	if (yPos > 0 && yPos <16) {
		yPos++;
	}
}


void car::checkCollision(EnemyCar *EC, bool *running) {
	if (EC->xPos == xPos && (EC->yPos == yPos || EC->yPos == yPos + 3 || EC->yPos == yPos - 1)) {
		*running = false;
	}
}
