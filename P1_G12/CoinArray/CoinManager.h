#pragma once
#include "Map.h"
class CoinManager
{
public:
	
	// Constructor CoinManager
	CoinManager(Map &mapClass);

private:

	// Struct per a les monedes del joc
	struct coinEstructure
	{
		int x, y;
	};

	// Aix�, creem un objecte de classe Map com a referencie en la nostra classe CoinManager, aix� fent que al inicialitzar aquest objecte en el constructor,
	// puguem utilitzar les funcions de la nostra classe Map. En resum, es una relaci� d'associaci�
	Map &myMap;

	// Nombre de monedes a recollir per a acabar la partida.
	int numCoins;
};