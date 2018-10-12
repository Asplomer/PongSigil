#include "Credit.h"
#include "Ejecutar.h"

//#include "raylib.h"
namespace Pong {
	void updateCredit() {
		if (IsKeyPressed(KEY_BACKSPACE)) {
			gameState = End;
		}
	}
	void drawCredit() {
		DrawText(FormatText("programador: Ariel Plomer"), 50, 70, 20, DARKGRAY);
		DrawText(FormatText("PONG FOR DUMMIES versión: 1.00"), 50, 100 , 20, DARKGRAY);
		DrawText(FormatText("software utilizado: visual studio 2017, raylib"), 50, 190, 20, DARKGRAY);
		DrawText(FormatText("presione BACKSPACE para salir"), 50, 190, 20, DARKGRAY);
			
	}

}