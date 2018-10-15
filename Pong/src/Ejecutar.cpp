#include "Ejecutar.h"
#include <iostream>
//#include "Credit.h"
//#include "Playstate.h"
//#include "GameOver.h"
//#include "Start.h"

using namespace std;
namespace Pong {
#define WHITE  CLITERAL{ 255, 255, 255, 255 }
	int screenWidth = 800;
	int screenHeight = 450;
	int score1 = 0;
	int score2 = 0;
	int gameState = 0;
	void ejecutar() {
		init();
		while (slShouldClose()!=0 && gameState != End) {
			updateEjecutar();
			allDraw();
		}
	}
	static void updateEjecutar() {
		switch (gameState) {
		case Start: {
		//	UpdateStart();

		}break;
		case Play: {
		//	updatePlay();

		}break;
		case GameOver: {
		//	UpdateOver();
		}break;
		case Credit: {
		//	updateCredit();

		}break;
		case End: {


		}break;
		}



	}
	static void allDraw() {
		//BeginDrawing();
		//ClearBackground(BLACK);

		switch (gameState) {
		case Start: {

		//	DrawStart();
		}break;
		case Play: {
		//	drawPlay();
		}break;
		case GameOver: {
		//	DrawOver();
		}break;
		case Credit: {
		//	drawCredit();

		}break;
		case End: {

		}break;
		}

		//EndDrawing();
	}
	static void init() {
		int screenWidth = 800;
		int screenHeight = 450;

		slWindow(screenWidth, screenHeight, "SIGIL SUCKS!, yet sigilPong", 0);

		bool exit = false;

		int score1 = 0;
		int score2 = 0;
		gameState = Start;


	}

}