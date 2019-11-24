#include <iostream>
#include "game.h"
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

///*
	int input = atoi(argv[1]);
	bool q = false;
	//char move[2];
	string move;

	Game game;
	
	game.createRooms(input);	

	while (!game.isOver()) {
		cout << "io:" << game.isOver() << "wk:" << game.wumpusKilled() << endl;
		game.printRooms();
		cout << "Use [w] [a] [s] [d] keys to move player." << endl;
		cout << "Hit the Spacebar then the direction";
		cout << " to fire your arrows." << endl; 
		getline(cin, move, '\n');
	//	if (move[0] == ' '){
	//	 	game.shootArrow();
	//	} 
		game.getPlayerAction(move[0]);
	}	
	return 0;
}
