#include "stdafx.h"
#include "Game.h"


HANDLE hThread;
HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
void colorit(int col)
{
	//12=red, 15=white
	SetConsoleTextAttribute(hstdout, col);
}
void myListener(car *c) {
	while (1) {
		if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0)) {
			c->moveLeft();
		}
		else if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 0)) {
			c->moveRight();
		}
		else if (GetAsyncKeyState(VK_UP) & (0x8000 != 0)) {
			c->moveUp();
		}
		else if (GetAsyncKeyState(VK_DOWN) & (0x8000 != 0)) {
			c->moveDown();
		}
	}
}

void startGame() {
	int score = 0, level = 1, speed = 105;
	system("cls");
	colorit(14); gotoXY(30, 2); cout << "  CONTROLS";
	gotoXY(30, 3); cout << "  ========";
	gotoXY(30, 5); cout << (char)17 << " LEFT ARROW";
	gotoXY(30, 7); cout << (char)16 << " RIGHT ARROW";
	gotoXY(30, 9); cout << (char)30 << " UP ARROW";
	gotoXY(30, 11); cout << (char)31 << " DOWN ARROW"; colorit(15);
<<<<<<< HEAD
	colorit(12); gotoXY(47, 5); cout << "- Every 3 score = level up";
	gotoXY(47, 7); cout << "- Level up = speed up"; colorit(15);


	for (int i = 3; i >= 0; i--) {
		gotoXY(33, 13); colorit(12); cout << "START " << i; colorit(15);
=======


	for (int i = 3; i >= 0; i--) {
		gotoXY(33, 13); colorit(9); cout << "START " << i; colorit(15);
>>>>>>> ba8258c5dfd32de5fe7e21e55b2042bf17cf457f
		gotoXY(14, 14);
		Sleep(1000);
	}
	system("cls");
	
	car mycar = car();
	EnemyCar myEnmCar = EnemyCar();
	EnemyCar myEnmCar2 = EnemyCar();
	// starts the second thread (The input listener )
	thread mySecondThread(myListener, &mycar);
	// This is the game engine/game loop
	bool running = true;
	srand(time(0));
	while (running)
	{
		colorit(10); gotoXY(14, 4); cout << "SCORE:" << score;
		gotoXY(14, 5); cout << "LEVEL:" << level; colorit(15);
		colorit(14); gotoXY(30, 2); cout << "  CONTROLS";
		gotoXY(30, 3); cout << "  ========";
		gotoXY(30, 5); cout << (char)17 << " LEFT ARROW";
		gotoXY(30, 7); cout << (char)16 << " RIGHT ARROW";
		gotoXY(30, 9); cout << (char)30 << " UP ARROW";
		gotoXY(30, 11); cout << (char)31 << " DOWN ARROW"; colorit(15);
<<<<<<< HEAD
		colorit(12); gotoXY(47, 5); cout << "- Every 3 score = level up";
		gotoXY(47, 7); cout <<"- Level up = speed up"; colorit(15);
=======
>>>>>>> ba8258c5dfd32de5fe7e21e55b2042bf17cf457f
		gotoXY(30, 15); colorit(8); Time(); colorit(15);
		resetBoard();
		myEnmCar.appear();
		myEnmCar.draw();
		myEnmCar.move();
		mycar.draw();
		myEnmCar2.appear();
		myEnmCar2.draw();
		myEnmCar2.move();
		mycar.checkCollision(&myEnmCar, &running);
		mycar.checkCollision(&myEnmCar2, &running);


		for (int j = 0; j<20; j++)
		{
			for (int i = 0; i<11; i++) {
				if (i == 0 || i == 10) {
					gotoXY(i, j);
					cout << "#";
				}

				else if (matrix[i][j] == 1) {
					gotoXY(i, j);
					cout << (char)5;
				}
				else {
					gotoXY(i, j);
					cout << " "; 
				}
			}

		}

<<<<<<< HEAD
		if (mycar.yPos+1 == myEnmCar.yPos-3  )
		{
			score++;
			if (score % 3 == 0) { 
				level++; 
			   if(level<7) speed-= 15;
			   else if (level >=8 && level<=10) speed -= 5;
			   else speed -= 1;
			}
			if (speed <= 0) { gotoXY(14, 3); colorit(12); cout << "YOU WIN!" << endl; colorit(15); running = 0; }
=======
		if (mycar.yPos+1 == myEnmCar.yPos-3)
		{
			score++;
			if (score % 2 == 0) { level++; speed = speed  - 15; }
			if (speed == 0) { gotoXY(14, 3); colorit(12); cout << "YOU WIN!" << endl; colorit(15); running = 0; }
>>>>>>> ba8258c5dfd32de5fe7e21e55b2042bf17cf457f

		}
		Sleep(speed);

	}// end while
		// Close the handle to the thread
	if (speed >0) { gotoXY(14, 4); colorit(12); cout << "YOU LOSE!" << endl; colorit(15); }
<<<<<<< HEAD
=======
	score = 1, level = 1, speed = 105;
>>>>>>> ba8258c5dfd32de5fe7e21e55b2042bf17cf457f
	Sleep(2000);
	system("cls");
	gotoXY(30, 15);
	gotoXY(5, 4);
	colorit(12); cout << "GAME OVER!!!"; colorit(15);
	gotoXY(5, 5);
	cout << "By:Kushpel Dmitry";
	gotoXY(0, 0);
	Sleep(2000);
	mySecondThread.detach();

}

void exitGame() {
	CloseHandle(hThread);
	system("cls");
	colorit(12); gotoXY(3, 3); cout << "GOOD BYE!"; colorit(15);
	colorit(15);
	Sleep(2000);
}

int showMenu() {
	system("cls");
	int ret = 1;
	int index = 1;
	int key = 0;
	while (key != 13) 
	{

		gotoXY(25, 3);
		colorit(15);
		cout << "RACE GAME";//cout<<key<<"---"<<index;
		gotoXY(25, 4);
		cout << "================";
		gotoXY(25, 6);
		colorit(15);
		if (index == 1) { colorit(12); }
		cout << "START GAME";
		gotoXY(25, 7);
		colorit(15);
		if (index == 2) { colorit(12); }
		cout << "EXIT";
		gotoXY(30, 10);
		colorit(15); cout << "By: Kushpel Dmitry"; colorit(15);
		gotoXY(0, 0);
		/////////////UP=224/72 Down=224/80 Enter=13
		key = _getch();
		if (key == 80) { index++; }
		else if (key == 72) { index--; }
		if (index == 3) { index = 1; }
		if (index == 0) { index = 2; }
	}
	 
	if (index == 1) {
		startGame();
	}
	else if (index == 2) {
		ret = 1;
		exitGame();
	}
	return ret;
}
