#include "CoinManager.h"
#include "Map.h"
#include <iostream>


// Constructor de Coin Manager, que depenent del nombre màxim de monedes i de les dimensions del mapa, fica en aquest
// cert nombre de monedes per a que el jugador les reculli.
CoinManager::CoinManager(Map &m, int coinsToWin) :myMap{m}, numCoins{coinsToWin}
{
	int nRows= m.rowGetter();
	int nColumns = m.columnGetter();
	actCoins= rand() % ((int)(nRows*nColumns*0.11))+((int)(nRows*nColumns*0.03));
	int i;
	int j;
	while (actCoins > 0)
	{
		i = rand() % nRows;
		j = rand() % nColumns;
		if (m.viewContent(i, j) == '.')
		{
			actCoins--;
			numCoins--;
			m.graellaModifier(i, j, '$');
		}
	}
}

// Mètode que ens permet eliminar una moneda del mapa o en cas de que no quedin monedes en aquest, hi fica les monedes restants per a acabar el joc.
void CoinManager::coinUpdate(Map &m, int i, int j,int actCoins,int numCoins)
{
	if(actCoins>0)
	{
		m.graellaModifier(i, j, '.');
	}
	else
	{
		while (numCoins > 0)
		{
			int nRows = m.rowGetter();
			int nColumns = m.columnGetter();
			i = rand() % nRows;
			j = rand() % nColumns;
			if (m.viewContent(i, j) == '.')
			{
				numCoins--;
				m.graellaModifier(i, j, '$');
			}
		}
	}
}