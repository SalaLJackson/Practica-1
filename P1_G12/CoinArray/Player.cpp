#include "Player.h"
#include "Input.h"
#include <conio.h>
#include <iostream>


// Constructor de Player: Aquest constructor inicialitza la posició del jugador, ho sigui, que inicialitza "x" i "y" de l'struct Player1.
// Després d'això, fica una arroba a la posició definida enteriorment, de manera que l'usuari podrà veure la seva posició en el mapa.
Player::Player(int Rows, int Columns, char** map)
{
	bool freeSpace = false;
	int i = 0, j = 0;
	while(freeSpace==false)
	{
		while(freeSpace==false)
		{
			if(map[i][j]=='.')
			{
				Player1.x = i;
				Player1.y = j;
				freeSpace = true;
			}
			j++;
		}
		i++;
	} 
	map[Player1.x][Player1.y] = '@';
}

//void Player::updatePosition()
//{
	
//}