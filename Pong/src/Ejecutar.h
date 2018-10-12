#ifndef EJECUTAR_H
#define EJECUTAR_H

#include "raylib.h"

namespace Pong {

#define WHITE  CLITERAL{ 255, 255, 255, 255 }
	extern int gameState;
	extern int screenWidth;
	extern int screenHeight;
	extern int score1;
	extern int score2;
#ifdef AUDIO
	extern Music music;
	extern Sound fxWav;
#endif
	enum State
	{
		Start,
		Play,
		GameOver,
		Credit,
		End
	};
	void ejecutar();
	static void updateEjecutar();
	static void allDraw();
	static void init();
};
#endif