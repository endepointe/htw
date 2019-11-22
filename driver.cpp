#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, char *argv[]) {

	srand(time(NULL));
	Game game;
	int input = atoi(argv[1]);
	int r = rand() % (input * input);
	vector<vector<Room*> > cave = game.createRooms(input);	
	game.createGrid(input, cave);

	cout << cave[0][0] << endl;
	cout << cave[0][0]->getEventChar() << endl;
	cave[0][0]->setEventChar('w');
	cave[0][1]->setEventChar('r');
	cave[0][2]->setEventChar('g');
	cave[0][3]->setEventChar('b');
	cave[0][4]->setEventChar('p');
	
	cout << (cave[0][0]->getEventChar() == 'w' ? cave[0][0]->emitPercept() : cave[0][0]->emitPercept()) << endl;
	cout << (cave[0][1]->getEventChar() == 'r' ? cave[0][1]->emitPercept() : cave[0][1]->emitPercept()) << endl;
	cout << (cave[0][2]->getEventChar() == 'g' ? cave[0][2]->emitPercept() : cave[0][2]->emitPercept()) << endl;
	cout << (cave[0][3]->getEventChar() == 'b' ? cave[0][3]->emitPercept() : cave[0][3]->emitPercept()) << endl;
	cout << (cave[0][4]->getEventChar() == 'p' ? cave[0][4]->emitPercept() : cave[0][4]->emitPercept()) << endl;

	cout << "wumpus event char: " << cave[0][0]->getEventChar() << endl;
	cout << "wumpus event char: " << cave[0][1]->getEventChar() << endl;
	cout << "wumpus event char: " << cave[0][2]->getEventChar() << endl;
	cout << "wumpus event char: " << cave[0][3]->getEventChar() << endl;
	cout << "wumpus event char: " << cave[0][4]->getEventChar() << endl;

/*
	while (r != ((input * input) - 1)) {
		r = rand() % (input * input);
		cout << r << endl;
	}
*/
	return 0;
}
