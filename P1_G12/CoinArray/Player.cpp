#include "Player.h"
#include "Input.h"
#include <conio.h>
#include <iostream>


// Constructor de Player: Aquest constructor inicialitza la posició del jugador, ho sigui, que inicialitza "x" i "y" de l'struct Player1.
// Després d'això, fica una arroba a la posició definida enteriorment, de manera que l'usuari podrà veure la seva posició en el mapa.
Player::Player(Map &m):myMap{ m }
{
	bool freeSpace = false;
	int Rows = m.rowGetter();
	int Columns = m.columnGetter();
	int i = rand() % Rows;
	int j = rand() % Columns;
	while(freeSpace==false && i<Rows)
	{
		while(freeSpace==false && j<Columns)
		{
			if(m.viewContent(i,j)=='.')
			{
				Player1.x = i;
				Player1.y = j;
				freeSpace = true;
			}
			j++;
		}
		i++;
	} 
	m.graellaModifier(i, j, '@');
}

void Player::updatePosition(Input::Key pressedKey)
{
	
}