#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, char *argv[]) {
	
	Game game;

	int input = atoi(argv[1]);

	vector<vector<Room*> > cave = game.createRooms(input);	
/*	
	cout << rooms[0][0] << endl;
	cout << "Has gold: " << rooms[0][0]->hasGold() << endl;
	cout << "Inserting gold..." << endl;
	rooms[0][0]->insertGold();
	cout << "Has gold: " << rooms[0][0]->hasGold() << endl;
*/

	game.createGrid(input, cave);

	return 0;
}
