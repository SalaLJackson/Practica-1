#pragma once

class Map
{
public:

	// Constructor Map
	Map(int gameDifficulty);

	// M�tode que modifica el contingut d'una graella
	void graellaModifier(int xPosition,int yPosition,char newContent);

	// M�tode que imprimeix el mapa per pantalla
	void drawMap();

private:

	// Nombre de files del nostre mapa
	int nRows; 
	// Nombre de columnes del nostre mapa
	int nColumns; 

	// A partir d'aquest punter de punters, farem el nostre "mapa".
	// Per a fer-ho, amb el constructor inicialitzarem nRows i nColumns, 
	// per a despr�s reservar espai en el heap a partir dels seus valors
	char ** mapArray; 
};

class Player
{
public:

	// Constructor Player
	Player(int Rows, int Columns, char** map);

private:

	struct estructuraPlayer
	{
		// Posicions del jugador
		int x; 
		int y;
	};
	estructuraPlayer Player1;
};