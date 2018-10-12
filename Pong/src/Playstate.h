#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include <iostream>
#include "raylib.h"
#include "Ejecutar.h"



using namespace std;
namespace Pong {

	const int POSX = 20;
	const float POSY = screenHeight / 2;
	const int WIDTH = 20;
	const int HEIGHT = 70;
	const int SQUARE = 20;
	const int BASESPEED = 2;
	const int TOPSCORE = 10;
	void updatePlay();
	void drawPlay();
}
#endif
