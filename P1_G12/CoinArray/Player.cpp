#include "Player.h"
#include "Input.h"
#include <conio.h>
#include <iostream>


// Constructor de Player: Aquest constructor inicialitza la posici� del jugador, ho sigui, que inicialitza "x" i "y" de l'struct Player1.
// Despr�s d'aix�, fica una arroba a la posici� definida enteriorment, de manera que l'usuari podr� veure la seva posici� en el mapa.
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