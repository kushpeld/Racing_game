#pragma once
#include "Field.h" 


class EnemyCar {
public:
	int xPos;
	int yPos;
	EnemyCar() { xPos = 5; yPos = -3; }
	void appear();
	void draw();
	void move();

};

