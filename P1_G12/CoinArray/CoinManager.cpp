#include "CoinManager.h"
#include "Map.h"
#include <iostream>

CoinManager::CoinManager(Map &m, int coinsToWin) :myMap{m}, numCoins{coinsToWin}
{
	int nRows= m.rowGetter();
	int nColumns = m.columnGetter();
	actCoins= rand() % ((int)(nRows*nColumns*0.11))+((int)(nRows*nColumns*0.03));
	for(int i=0;i<nRows && actCoins>0;i++)
	{
		for(int j=0;j<nColumns && actCoins>0;j++)
		{
			if(m.viewContent(i,j)=='.')
			{
				actCoins--;
				m.graellaModifier(i, j, '$');
			}
		}
	}
	
}