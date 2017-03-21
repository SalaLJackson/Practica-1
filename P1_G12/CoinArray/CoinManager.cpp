#include "CoinManager.h"
#include "Map.h"
#include <iostream>

CoinManager::CoinManager(Map &m) :myMap{m}
{
	int nRows= m.rowGetter();
	int nColumns = m.columnGetter();
	numCoins= rand() % ((int)(nRows*nColumns*0.11))+((int)(nRows*nColumns*0.03));
	//coinEstructure Coins[numCoins];
}