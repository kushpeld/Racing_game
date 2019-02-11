#pragma once

#include <windows.h>
#include <iostream>
#include <chrono>
#include <ctime>    
#include <thread>
#include <string>
#include<stdlib.h>

using namespace std;
extern int matrix[11][20];
void Time();
void gotoXY(int x, int y);
void drawPoint(int x, int y);
void resetBoard();

