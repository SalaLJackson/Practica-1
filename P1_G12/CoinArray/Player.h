#pragma once
#include "Input.h"
#include "CoinManager.h"
#include "Map.h"

class Player
{
public:

	// Constructor Player
	Player(Map &mapClass, CoinManager &cm);

	// Mètode que actualitza la posició del jugador
	void updatePosition(Input::Key pressedKey, Map &m, CoinManager &cm);

	// Getter de la puntuació
	int getPuntuacio();

private:

	struct estructuraPlayer
	{
		// Posicions del jugador
		int x;
		int y;
	};
	estructuraPlayer Player1;

	Map &myMap;

	CoinManager &myCoinManager;

	// Nombre de monedes recollides.
	int puntuacio;
};