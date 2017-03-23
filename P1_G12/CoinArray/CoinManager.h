#pragma once
#include "Map.h"
class CoinManager
{
public:
	
	// Constructor CoinManager
	CoinManager(Map &mapClass,int coinsToWin);

	// Mètode que permet eliminar una moneda i en cas de que no n'hi hagin més en el mapa, torna a ficar-ne
	void coinUpdate(Map &mapClass,int xPosition,int yPosition);

	// Getter actCoins
	int actCoinsGetter();

	// Getter numcoins
	int numCoinsGetter();

private:

	// Així, creem un objecte de classe Map com a referencie en la nostra classe CoinManager, així fent que al inicialitzar aquest objecte en el constructor,
	// puguem utilitzar les funcions de la nostra classe Map. En resum, es una relació d'associació
	Map &myMap;

	// Nombre de monedes a recollir per a acabar la partida.
	int numCoins;

	// Nombre de monedes actualment en el mapa.
	int actCoins;
};