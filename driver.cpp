#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, char *argv[]) {

	srand(time(NULL));
	Game game;
	int input = atoi(argv[1]);
	int r = rand() % (input * input);
	bool q = false;
	char move;
	
	game.createRooms(input);	

	while (!q) {
		game.printRooms();
		cout << "move player using wasd: " << endl;
		cin >> move;
		game.movePlayer(move);
	}	

	return 0;
}
