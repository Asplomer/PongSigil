#include "Ejecutar.h"
#include <iostream>
#include "Credit.h"
#include "Playstate.h"
#include "GameOver.h"
#include "Start.h"

using namespace std;
namespace Pong {
#define WHITE  CLITERAL{ 255, 255, 255, 255 }
	int screenWidth = 800;
	int screenHeight = 450;
	int score1 = 0;
	int score2 = 0;
	int gameState = 0;
#ifdef AUDIO
	Music music;
	Sound fxWav;

#endif


	void ejecutar() {
		init();
		while (!WindowShouldClose() && gameState != End) {
			updateEjecutar();
			allDraw();
		}
	}
	static void updateEjecutar() {
#ifdef AUDIO
		UpdateMusicStream(music);
#endif
		switch (gameState) {
		case Start: {
			UpdateStart();

		}break;
		case Play: {
			updatePlay();

		}break;
		case GameOver: {
			UpdateOver();
		}break;
		case Credit: {
			updateCredit();

		}break;
		case End: {


		}break;
		}



	}
	static void allDraw() {
		BeginDrawing();
		ClearBackground(BLACK);

		switch (gameState) {
		case Start: {

			DrawStart();
		}break;
		case Play: {
			drawPlay();
		}break;
		case GameOver: {
			DrawOver();
		}break;
		case Credit: {
			drawCredit();

		}break;
		case End: {

		}break;
		}

		EndDrawing();
	}
	static void init() {
		int screenWidth = 800;
		int screenHeight = 450;

		InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
#ifdef AUDIO
		InitAudioDevice();

		music = LoadMusicStream("res/menusong.ogg");
		fxWav = LoadSound("res/Hit_Hurt.wav");
		PlayMusicStream(music);
#endif
		SetExitKey(0);

		bool exit = false;

		int score1 = 0;
		int score2 = 0;
		gameState = Start;


	}

}