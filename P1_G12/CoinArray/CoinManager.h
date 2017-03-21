#pragma once
#include "Map.h"
class CoinManager
{
public:
	
	// Constructor CoinManager
	CoinManager(Map &mapClass,int coinsToWin);

private:

	// Així, creem un objecte de classe Map com a referencie en la nostra classe CoinManager, així fent que al inicialitzar aquest objecte en el constructor,
	// puguem utilitzar les funcions de la nostra classe Map. En resum, es una relació d'associació
	Map &myMap;

	// Nombre de monedes a recollir per a acabar la partida.
	int numCoins;

	// Nombre de monedes actualment en el mapa.
	int actCoins;
};