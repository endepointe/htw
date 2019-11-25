#include <iostream>
#include "game.h"
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

///*
	int input = atoi(argv[1]);
	string debug = argv[2];

	if (input < 4) {
		cout << "Dimension cannot be smaller the 4, run the program again." << endl;
		exit(0);
	}

	string move;

	Game game;

	game.createRooms(input);

	if (debug == "true") {
		while (!game.isOver()) {
			game.printDevRooms();
			game.printInstructions();
			getline(cin, move, '\n');
			game.getPlayerAction(move[0]);
		}	
	} 

	if (debug == "false") {
		while (!game.isOver()) {
			game.printProdRooms();
			game.printInstructions();
			getline(cin, move, '\n');
			game.getPlayerAction(move[0]);
		}
	}

	return 0;
}
