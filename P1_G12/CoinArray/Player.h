#pragma once
class Player
{
public:

	// Constructor Player
	Player(int Rows, int Columns, char** map);

	// M�tode que actualitza la posici� del jugador
	//void updatePosition(Key pressedKey);

private:

	struct estructuraPlayer
	{
		// Posicions del jugador
		int x;
		int y;
	};
	estructuraPlayer Player1;
};