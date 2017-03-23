#include "Player.h"
#include "Input.h"
#include <conio.h>
#include <iostream>


// Constructor de Player: Aquest constructor inicialitza la posició del jugador, ho sigui, que inicialitza "x" i "y" de l'struct Player1.
// Després d'això, fica una arroba a la posició definida enteriorment, de manera que l'usuari podrà veure la seva posició en el mapa.
Player::Player(Map &m, CoinManager &cm):myMap{ m },puntuacio{0}, myCoinManager{cm}
{
	bool freeSpace = false;
	int Rows = m.rowGetter();
	int Columns = m.columnGetter();
	int i, j;
	while(freeSpace==false)
	{
		i = rand() % Rows;
		j = rand() % Columns;
		if(m.viewContent(i,j)=='.')
		{
			Player1.x = i;
			Player1.y = j;
			freeSpace = true;
		}	
	} 
	m.graellaModifier(Player1.x, Player1.y, '@');
}

void Player::updatePosition(Input::Key pressedKey, Map &m, CoinManager &cm)
{
	char nextPosition; // Variable que guardarà el contingut de la posició que el jugador ocuparà al presionar una de les tecles disponibles.
	int actCoins = cm.actCoinsGetter();
	int numCoins = cm.numCoinsGetter();
	int columna= m.columnGetter();
	int fila=m.rowGetter();
	switch(pressedKey)
	{
		case(Input::Key::W):
		{
			if (Player1.x > 0)
			{
				nextPosition = m.viewContent(Player1.x - 1, Player1.y);
				if (nextPosition == '$')
				{
					puntuacio++;
					cm.coinUpdate(m, Player1.x - 1, Player1.y);
				}
				Player1.x--;
				m.graellaModifier(Player1.x, Player1.y, '@');
				m.graellaModifier(Player1.x + 1, Player1.y, '.');
			}
			break;
		}
		case(Input::Key::A):
		{
			if (Player1.y > 0)
			{
				nextPosition = m.viewContent(Player1.x, Player1.y - 1);
				if (nextPosition == '$')
				{
					puntuacio++;
					cm.coinUpdate(m, Player1.x, Player1.y - 1);
				}
				Player1.y--;
				m.graellaModifier(Player1.x, Player1.y, '@');
				m.graellaModifier(Player1.x, Player1.y + 1, '.');
			}
			break;
		}
		case(Input::Key::S):
		{
			if (Player1.x != fila-1)
			{
				nextPosition = m.viewContent(Player1.x + 1, Player1.y);
				if (nextPosition == '$')
				{
					puntuacio++;
					cm.coinUpdate(m, Player1.x + 1, Player1.y);
				}
				Player1.x++;
				m.graellaModifier(Player1.x, Player1.y, '@');
				m.graellaModifier(Player1.x - 1, Player1.y, '.');
			}
			break;
		}
		case(Input::Key::D):
		{
			if (Player1.y != columna-1)
			{
				nextPosition = m.viewContent(Player1.x, Player1.y + 1);
				if (nextPosition == '$')
				{
					puntuacio++;
					cm.coinUpdate(m, Player1.x, Player1.y + 1);
				}
				Player1.y++;
				m.graellaModifier(Player1.x, Player1.y, '@');
				m.graellaModifier(Player1.x, Player1.y - 1, '.');
			}
			break;
		}
	}
}

int Player::getPuntuacio()
{
	return puntuacio;
}