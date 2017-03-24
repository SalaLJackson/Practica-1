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
	numCoins = numCoins - actCoins;
	int i;
	int j;
	int coinsCounter=0;
	while (coinsCounter!=actCoins)
	{
		i = rand() % nRows;
		j = rand() % nColumns;
		if (m.viewContent(i, j) == '.')
		{
			m.graellaModifier(i, j, '$');
			coinsCounter++;
		}
	}
}

// Mètode que ens permet eliminar una moneda del mapa o en cas de que no quedin monedes en aquest, hi fica les monedes restants per a acabar el joc.
void CoinManager::coinUpdate(Map &m, int i, int j)
{
	if(actCoins>0)
	{
		m.graellaModifier(i, j, '.');
		actCoins--;
	}
	if(actCoins==0)
	{
		int nRows = m.rowGetter();
		int nColumns = m.columnGetter();
		actCoins = rand() % ((int)(nRows*nColumns*0.11)) + ((int)(nRows*nColumns*0.03));
		int x;
		int y;
		int coinsCounter = 0;
		while (coinsCounter != actCoins)
		{
			x = rand() % nRows;
			y = rand() % nColumns;
			if (m.viewContent(x, y) == '.')
			{
				m.graellaModifier(x, y, '$');
				coinsCounter++;
			}
		}
		numCoins = numCoins - actCoins;
	}
}

int CoinManager::numCoinsGetter()
{
	return numCoins;
}

int CoinManager::actCoinsGetter()
{
	return actCoins;
}

void CoinManager::actCoinsDec()
{
	actCoins--;
}

void CoinManager::numCoinsSetter(int n)
{
	numCoins = n;
}