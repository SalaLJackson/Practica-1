#include "Map.h"
#include <iostream>

// Constructor de Map: En aquest cridem el "constructor de variables" i donem valors a nRows i nColumns, 
// dos variables que depenen de gameDifficulty, el qual serà introduït per l'usuari. Per altra banda, també
// reservarem espai en el heap (aquest espai depén de nRows), la direcció del qual serà apuntada pel punter mapArray.
// A més a més, cada un dels espais anteriorment creats a partir de nRows serà en sí un punter, el qual apuntarà
// als nous espais reservats a partir de nColumns. En definitiva, el que haurem fet serà crear un Array Dinàmic
// a partir d'utilitzar punters de punters.
Map::Map(int gameDifficulty) : nRows{ 5 * gameDifficulty }, nColumns{ 5 * gameDifficulty * 2 }, mapArray{new char*[nRows]}
{
	for (int i = 0; i < nRows; i++) 
	{
		mapArray[i] = new char[nColumns];
	}
}

// Reemplaça el contingut d'una graella.
void Map::graellaModifier(int xPosition, int yPosition, char newContent) 
{
	mapArray[xPosition][yPosition] = newContent;
}

// Imprimeix el mapa per pantalla.
void Map::drawMap()
{
	for (int i = 0; i < nRows; i++) 
	{
		for (int j = 0; j < nColumns; j++) 
		{
			std::cout << mapArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Omple totes les graelles del mapa amb punts
void Map::fillDots()
{
	for(int i=0;i<nRows;i++)
	{
		for(int j=0;j<nColumns;j++)
		{
			mapArray[i][j] = '.';
		}
	}
}

// Un getter que retorna el nombre de files del mapa
int Map::rowGetter()
{
	return nRows;
}

// Un getter que retorna el nombre de columnes del mapa

int Map::columnGetter()
{
	return nColumns;
}

// Retorna el contingut d'un punt en el mapa

char Map::viewContent(int i, int j)
{
	return mapArray[i][j];
}