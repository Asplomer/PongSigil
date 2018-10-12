#include "GameOver.h"
#include "Ejecutar.h"
#include "raylib.h"
namespace Pong {

	void UpdateOver() {
		if (IsKeyPressed(KEY_S)) {
			gameState = Play;

			score1 = 0;
			score2 = 0;
		}
		if (IsKeyPressed(KEY_N)) gameState = Credit;
	}
	void DrawOver() {
		if (score1 > score2) {
			DrawText(FormatText("el primer jugador gano con un puntaje de %i contra %i", score1, score2), POSXTEXT, POSYTEXT, SIZETEXT, DARKGRAY);
		}
		else if (score1 < score2) {
			DrawText(FormatText("el Segundo jugador gano con un puntaje de %i contra %i", score2, score1), POSXTEXT, POSYTEXT, SIZETEXT, DARKGRAY);
		}
		else {}

		DrawText(FormatText("Quiere jugar de nuevo? S/N"), 50, 80, 20, DARKGRAY);
	}

}