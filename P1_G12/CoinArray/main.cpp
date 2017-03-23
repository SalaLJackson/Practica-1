#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include "Map.h"
#include "CoinManager.h"
#include "Player.h"
#include "Input.h"

void main() 
{
	// INICIALITZACIÓ-----------------------------------------------------------------------------------------------------------------------------

	srand(static_cast<unsigned>(2));// Canvia la seed per a obtenir resultats diferents cada cop que el programa es executat.

	int gD; // gD: Aquesta variable guardarà el valor de la Dificultat del joc.

	int coinsToWin; // coinsToWin: Guarda el nombre de monedes necessaries per a completar la partida.

	bool difficultyCorrect=false; // difficultyCorrect: Boolea que ens serivirà per saber si la dificultat introduida és correcte.

	Input::Key pressedKey; // pressedKey: Aquesta variable guardarà la tecla presa pel jugador

	// Imprimim els missatges d'introducció:
	// El títol, els controls i el selector de dificultat
	std::cout << "//////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "                                             COIN RACE                                        " << std::endl;
	std::cout << "//////////////////////////////////////////////////////////////////////////////////////////////" << std::endl << std::endl;
	std::cout << "Controls: Utilitza WASD per a moure el teu personatge" << std::endl << std::endl;
	std::cout << "Escull una dificultat: " << std::endl;
	std::cout << "1 - FACIL" << std::endl;
	std::cout << "2 - MITJANA" << std::endl;
	std::cout << "3 - DIFICIL" << std::endl;
	while(difficultyCorrect==false)
	{
		std::cin >> gD;
		if(gD<1 || gD>3)
		{
			std::cout << "DIFICULTAT INCORRECTE, TORNA A INTRODUIR-LA" << std::endl;
		}
		else
		{
			difficultyCorrect = true;
		}
	}
	coinsToWin = rand()% ((30*gD)+1)+(30*gD); // Inicialitza el valor de les monedes entre 30*gD i 30*2*gD. Com que anteriorment utilitzem srand(), el nombre serà aleatori en cada execució.
	Map actualMap(gD);
	actualMap.fillDots(); // Totes les graelles del mapa s'inicialitzaràn com a punts per defecte.
	system("cls");
	actualMap.drawMap();
	system("cls");
	CoinManager coinManaging(actualMap,coinsToWin);
	Player myPlayer(actualMap,coinManaging);
	actualMap.drawMap();
	// ACTUALITZACIÓ------------------------------------------------------------------------------------------------------------------------------
	while(coinManaging.numCoinsGetter()>0)
	{
		pressedKey = Input::getKey();
		if(pressedKey!=Input::Key::NONE)
		{
			myPlayer.updatePosition(pressedKey, actualMap,coinManaging);
			system("cls");
			actualMap.drawMap();
			std::cout << "La teva puntuacio es de: " << myPlayer.getPuntuacio() << std::endl;
		}
	}
	system("cls");
	std::cout << "FELICITATS GUANYADOR" << std::endl;
	std::cout << "Puntuacio: " << myPlayer.getPuntuacio() << std::endl;
	std::cout << "Temps Invertit: " << clock()/1000 << " segons" << std::endl;
}