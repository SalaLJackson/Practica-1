#pragma once
class Map
{
public:

	// Constructor Map
	Map(int gameDifficulty);

	// Mètode que modifica el contingut d'una graella
	void graellaModifier(int xPosition, int yPosition, char newContent);

	// Mètode que imprimeix el mapa per pantalla
	void drawMap();

	// EXTRA: Mètode que omple tots els espais del mapa amb ".". 
	void fillDots();

private:

	// Nombre de files del nostre mapa
	int nRows;
	// Nombre de columnes del nostre mapa
	int nColumns;

	// A partir d'aquest punter de punters, farem el nostre "mapa".
	// Per a fer-ho, amb el constructor inicialitzarem nRows i nColumns, 
	// per a després reservar espai en el heap a partir dels seus valors
	char ** mapArray;
};
