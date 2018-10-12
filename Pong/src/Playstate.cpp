#include "Playstate.h"
namespace Pong {

	static Rectangle ball = { (float)screenWidth / 2, (float)screenHeight / 2 ,(float)SQUARE, (float)SQUARE };//x,y,w,h
	static Rectangle bar1 = { (float)POSX, (float)POSY, (float)WIDTH, (float)HEIGHT };
	static Rectangle bar2 = { (float)screenWidth - 50, 0.0f + (float)POSY, (float)WIDTH, (float)HEIGHT };
	static bool started = false;
	static int ran = 0;
	static float angle = 0.5f;
	static float speedBoost = 0.0f;
	static bool ballUp = true;
	static bool ballLeft = true;




	void updatePlay() {


		if (IsKeyDown(KEY_UP) && bar1.y > 0) bar1.y -= 5.0f * 60 * GetFrameTime();
		if (IsKeyDown(KEY_DOWN) && bar1.y + bar1.height < screenHeight) bar1.y += 5.0f * 60 * GetFrameTime();

		if (IsKeyDown(KEY_O) && bar2.y > 0) bar2.y -= 5.0f * 60 * GetFrameTime();
		if (IsKeyDown(KEY_L) && bar2.y + bar2.height < screenHeight) bar2.y += 5.0f * 60 * GetFrameTime();

		if (ballLeft) {
			ball.x += (2.5f + speedBoost)*acosf((float)angle) * 60 * GetFrameTime();

		}
		else {
			ball.x -= (2.5f + speedBoost)*acosf((float)angle) * 60 * GetFrameTime();

		}
		if (ballUp) {
			ball.y += (2.5f + speedBoost)* asinf((float)angle) * 60 * GetFrameTime();
		}
		else {
			ball.y -= (2.5f + speedBoost)* asinf((float)angle) * 60 * GetFrameTime();
		}



		//chequea colisiones con las paletas, falta la colision a los "laterales" de ellas;
		//UPDATE: segun la pos de y en donde pega la bola, usar seno o coseno y multiplicarlo con un angulo max ej:
		// si pega en el centro, va a dar sen(0) * 45º= 0º y si pega arriba-> sen(-30) * 45º = -45º; con valores intermedios dando entre esos angulos
		//usando cmath
		if (CheckCollisionRecs(bar1, ball) || CheckCollisionRecs(bar2, ball)) {
			if (ballLeft && CheckCollisionRecs(bar2, ball)) {
#ifdef AUDIO
				PlaySound(fxWav);
#endif
				if (ball.x > bar2.x && ball.y < bar2.y + bar2.height) {
					ball.y = bar2.y - ball.height+1;
					ballUp = false;
				}
				else
					if (ball.x > bar2.x && ball.y > bar2.y - ball.height) {
						ball.y = bar2.y + bar2.height-1;
						ballUp = true;
					}
					//else
						ballLeft = false;
#ifdef AUDIO
				PlaySound(fxWav);
#endif

				ball.x -= 2/*screenWidth - 45 - SQUARE*/;
				speedBoost += 0.3f;
			}
			else if (!ballLeft && CheckCollisionRecs(bar1, ball)) {
				
				if (ball.x < bar1.x && ball.y < bar1.y - bar1.height) {
					ball.y = bar1.y - bar1.height-1;
					ballUp = false;
				}
				else
					if (ball.x < bar1.x && ball.y > bar1.y + ball.height) {
						ball.y = bar1.y + bar1.height+1;
						ballUp = true;
					}
					//else
				ballLeft = true;
#ifdef AUDIO
				PlaySound(fxWav);
#endif
				ball.x += 2;
				speedBoost += 0.3f;
			}


		}

		if ((ball.y < 0 && !ballUp) || (ball.y + ball.height > screenHeight && ballUp)) {
			if (ballUp)ballUp = false;
			else ballUp = true;
		}

		if (ball.x >= screenWidth) {
			started = false;
			score1++;
		}
		if (ball.x + ball.width <= 0) {
			started = false;
			score2++;
		}

		if (!started) {
			ran = GetRandomValue(1, 4);
			angle = 0.5f;
			speedBoost = 0.0f;
			ballUp = true;
			ballLeft = true;
			if (ran == 1 || ran == 3)
				ballUp = false;
			if (ran == 1 || ran == 2)
				ballLeft = false;
			ball.x = (float)screenWidth / 2;
			ball.y = (float)screenHeight / 2;
			started = true;
		}
		if (score1 >= TOPSCORE || score2 >= TOPSCORE) {
			gameState = GameOver;
#ifdef AUDIO
			UnloadSound(fxWav);
			UnloadMusicStream(music);
			CloseAudioDevice();
#endif
		}


	}
	void drawPlay() {

		DrawText(FormatText("%i", score1), screenWidth / 2 - 40, 10, 40, DARKGRAY);
		DrawText(FormatText("/"), screenWidth / 2 - 10, 10, 40, DARKGRAY);
		DrawText(FormatText("%i", score2), screenWidth / 2 + 25, 10, 40, DARKGRAY);

		DrawText(FormatText("Controles:    paleta isquierda: arriba y abajo,    paleta derecha: ' O ' y ' L '"), 50, screenHeight - 50, 18, DARKGRAY);



		DrawRectangleRec(ball, WHITE);
		DrawRectangleRec(bar1, WHITE);
		DrawRectangleRec(bar2, WHITE);

	}
}