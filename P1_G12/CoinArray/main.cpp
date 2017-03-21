#include <iostream>
#include <ctime>
#include <conio.h>
#include "Map.h"
#include "Input.h"

void main() 
{
	// INICIALITZACI�-----------------------------------------------------------------------------------------------------------------------------

	srand(static_cast<unsigned>(time(nullptr))); // Canvia la seed per a obtenir resultats diferents cada cop que el programa es executat.

	int gD; // gD: Aquesta variable guardar� el valor de la Dificultat del joc.

	int coinsToWin; // coinsToWin: Guarda el nombre de monedes necessaries per a completar la partida.

	Input::Key pressedKey; // pressedKey: Aquesta variable guardar� la tecla presa pel jugador

	// Imprimim els missatges d'introducci�:
	// El t�tol, els controls i el selector de dificultat
	std::cout << "//////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "                                             COIN RACE                                        " << std::endl;
	std::cout << "//////////////////////////////////////////////////////////////////////////////////////////////" << std::endl << std::endl;
	std::cout << "Controls: Utilitza WASD per a moure el teu personatge" << std::endl << std::endl;
	std::cout << "Escull una dificultat: " << std::endl;
	std::cout << "1 - FACIL" << std::endl;
	std::cout << "2 - MITJANA" << std::endl;
	std::cout << "3 - DIFICIL" << std::endl;
	std::cin >> gD;
	coinsToWin = rand()% ((30*gD)+1)+(30*gD); // Inicialitza el valor de les monedes entre 30*gD i 30*2*gD. Com que anteriorment utilitzem srand(), el nombre ser� aleatori en cada execuci�.
	Map actualMap(gD);
	actualMap.fillDots(); // Totes les graelles del mapa s'inicialitzar�n com a punts per defecte.
	actualMap.drawMap();

	// ACTUALITZACI�------------------------------------------------------------------------------------------------------------------------------
}