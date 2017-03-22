#pragma once
#include "Input.h"
#include "CoinManager.h"
#include "Map.h"

class Player
{
public:

	// Constructor Player
	Player(Map &mapClass);

	// M�tode que actualitza la posici� del jugador
	void updatePosition(Input::Key pressedKey);

private:

	struct estructuraPlayer
	{
		// Posicions del jugador
		int x;
		int y;
	};
	estructuraPlayer Player1;

	Map &myMap;
};