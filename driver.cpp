#include <iostream>
#include "game.h"
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

	int input = atoi(argv[1]);
	string debug = argv[2];

	if (input < 4) {
		cout << "Dimension cannot be smaller the 4, run the program again." << endl;
		exit(0);
	}

	string move;

	Game game;

	game.createRooms(input);

	while (!game.isOver()) {
		if (debug == "true") {
			game.printDevRooms();
		} else {
			game.printProdRooms();
		}
		game.printInstructions();
		getline(cin, move, '\n');
		game.getPlayerAction(move[0]);
	}	

	return 0;
}
