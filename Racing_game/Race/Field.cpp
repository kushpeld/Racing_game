#include "stdafx.h"
#include "Field.h"

using namespace std;
int matrix[11][20];
void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawPoint(int x, int y) {
	if (y<20 && y >= 0) {
		matrix[x][y] = 1;
	}
}
void resetBoard() {
	for (int j = 0; j<20; j++)
	{
		for (int i = 1; i<10; i++) {
			matrix[i][j] = 0;
		}
	}
}
void Time(){
auto end = chrono::system_clock::now();
time_t end_time = chrono::system_clock::to_time_t(end);

cout <<  ctime(&end_time) << endl;

}