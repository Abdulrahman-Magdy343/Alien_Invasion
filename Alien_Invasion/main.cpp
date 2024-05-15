#include <iostream>
#include "Deque.h"
#include "Game.h"
using namespace std;

int main()
{
	Game* game = new Game();
	game->go();
	game->generateOutputFile("battle_output.txt");


}