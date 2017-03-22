#pragma once
#include "Input.h"
class Player
{
public:

	// Constructor Player
	Player(int Rows, int Columns, char** map);

	// Mètode que actualitza la posició del jugador
	void updatePosition(Input::Key pressedKey);

private:

	struct estructuraPlayer
	{
		// Posicions del jugador
		int x;
		int y;
	};
	estructuraPlayer Player1;
};