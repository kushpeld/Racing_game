#include "stdafx.h"
#include "EnemyCar.h"

void EnemyCar::appear() {
	if (yPos == 20) {

		int randomNo = rand() % 3;
		if (randomNo == 0) {
			xPos = 2;
		}
		else if (randomNo == 1) {
			xPos = 5;
		}
		else { xPos = 8; }
		yPos = -3;
	}
}
void EnemyCar::draw() {
	drawPoint(xPos, yPos);
	drawPoint(xPos - 1, yPos + 1);
	drawPoint(xPos + 1, yPos + 1);
	drawPoint(xPos, yPos + 1);
	drawPoint(xPos, yPos + 2);
	drawPoint(xPos - 1, yPos + 3);
	drawPoint(xPos + 1, yPos + 3);
	drawPoint(xPos, yPos + 3);
}
void EnemyCar::move() {
	yPos++;
}