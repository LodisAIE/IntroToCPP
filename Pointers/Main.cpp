#include <iostream>
#include "Game.h"

void changeNumber(int& num){
	num = 5;
}

int main()
{
	Game game = Game();
	game.run();
	return 0;
}