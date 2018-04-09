/********************
** Author: Kelvin Lu
** Date: 10/16/2017
** Description: This is the main function for playing the game.
********************/
#include "Zoo.hpp"
#include <stdlib.h>
#include <time.h>

int main()
{	
	srand(time(NULL));
	ZooUI newGame;

	newGame.initialBuy();
	newGame.dailyEvents();
	newGame.gameOver();
}
