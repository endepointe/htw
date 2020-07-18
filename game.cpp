#include <vector>
#include <ctype.h>
#include "game.h"
#include "event.h"
#include "room.h"
#include "wumpus.h"
#include <iostream>

using namespace std;

/******************************************************************************
 * Function: Game constructor
 * Desc: Controls the creation of game assets
 * Params: grid count that forms an X x Y grid (e.g. - 4 x 4)
 * Pre: rooms do no exist
 * Post: rooms are created 
 * ***************************************************************************/
Game::Game() {
	srand(time(NULL));
	gameOver = false;
	killedWumpus = false;
	foundAndReturned = false;
	goldFound = false;
	touchedWumpus = false;
	fellInPit = false;
	again = true;
}

Game::~Game() {
	//vector<vector<Room*> > rooms;
	///*
	for (int i = 0; i < caveSize; i++) {
		for (int j = 0; j < caveSize; j++) {
			//rooms[i].pop_back();
			delete rooms[i][j];
		}
		rooms[i].clear();
		//rooms[i].pop_back();
	}//*/
	//rooms.pop_back();
	//rooms.resize(0);
	rooms.clear();
}

/**************************************************************************
 * Function: createRooms
 * Desc: creates the rooms of type vector and sets the caveSize
 * Params: int 
 * Pre: a grid doesnt exist
 * Post: a grid is filled with vector
 * ***********************************************************************/
void Game::createRooms(int count) {

	// Set the caveSize for use later
	caveSize = count;

	for (int i = 0; i < count ;i++) {
	
		vector<Room*> row; 

		for (int j = 0; j < count; j++) {
			row.push_back(new Room);
		}			

		rooms.push_back(row);
	}
///*
	setBats();
	setWumpus();
	setGold();
	setPits();
	setRope();
//*/
}

/**************************************************************************
 * Function: printDevRooms 
 * Desc: creates a grid of specific size with a vector in dev mode
 * Params: int 
 * Pre: a grid doesnt exist
 * Post: a grid is filled with vector
 * ***********************************************************************/
void Game::printDevRooms() {

	int row = caveSize;
	int col = caveSize;
	char newChar;
	
	vector<char> ceil = {'+', '-', '-', '-'};
	vector<char> wall = {'|',' ', ' ',' '};

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
			for (char it : ceil) {
				cout << it;
			}	
		}

		cout << "+" << endl;
		
		for (int j = 0; j < col; j++) {
			{rooms[i][j]->hasPlayer() ? newChar = '*' : newChar = rooms[i][j]->getEventChar(); };
			wall[2] = newChar;
			for (char it : wall) {
				cout << it;
			}
		}

		cout << "|" << endl;
	}	

	for (int j = 0; j < col; j++) {
			for (char it : ceil) {
				cout << it;
			}	
		}
	cout << "+" << endl;
};

/**************************************************************************
 * Function: printProdRooms 
 * Desc: creates a grid of specific size with a vector in prod mode
 * Params: int 
 * Pre: a grid doesnt exist
 * Post: a grid is filled with vector
 * ***********************************************************************/
void Game::printProdRooms() {

	int row = caveSize;
	int col = caveSize;
	char newChar;
	
	vector<char> ceil = {'+', '-', '-', '-'};
	vector<char> wall = {'|',' ', ' ',' '};

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
			for (char it : ceil) {
				cout << it;
			}	
		}

		cout << "+" << endl;
		
		for (int j = 0; j < col; j++) {
			{rooms[i][j]->hasPlayer() ? newChar = '*' : newChar = ' '; };
			wall[2] = newChar;
			for (char it : wall) {
				cout << it;
			}
		}

		cout << "|" << endl;
	}	

	for (int j = 0; j < col; j++) {
			for (char it : ceil) {
				cout << it;
			}	
		}
		cout << "+" << endl;
};

/**************************************************************************
 * Function: printIntructions 
 * Desc: prints the intructions to play the game 
 * Params: none 
 * Pre: none 
 * Post: none 
 * ***********************************************************************/
void Game::printInstructions() {
	cout << "Use [w] [a] [s] [d] keys to move player." << endl;
	cout << "Hit the Spacebar, then Enter, then the direction";
	cout << " to fire your arrows." << endl; 
}

/**************************************************************************
 * Function: setBats 
 * Desc: sets two bats in cave 
 * Params: none 
 * Pre: bats dont exist 
 * Post: a grid is filled with two 
 * ***********************************************************************/
void Game::setBats() {

	int rx;
	int ry;
	bool has = false;
	
	for (int i = 0; i < bats; i++) {
		has = false;
		while (!has) {
			rx = rand() % caveSize;
			ry = rand() % caveSize;
			char check = rooms[ry][rx]->getEventChar(); 
			if (check == ' ') {	
				rooms[ry][rx]->setEventChar('B');
				rooms[ry][rx]->createPercept();
				if (i == 0) {
					batLY1 = ry;
					batLX1 = rx;	
				}
				if (i == 1) {
					batLY2 = ry;
					batLX2 = rx;	
				}
				has = true;
			}
		}	
	}
}

/**************************************************************************
 * Function: setWumpus 
 * Desc: sets wumpus 
 * Params: none 
 * Pre: wumpus not on map 
 * Post: wumpus is 
 * ***********************************************************************/
void Game::setWumpus() {

	int rx;
	int ry;
	int x,y;
	bool has = false;

	for (int i = 0; i < wumpus; i++) {
		has = false;
		while (!has) {
			rx = rand() % caveSize;
			ry = rand() % caveSize;		
			char check = rooms[ry][rx]->getEventChar(); 
			if (check == ' ') {	
				rooms[ry][rx]->setEventChar('W');
				rooms[ry][rx]->createPercept();
				wumpusLX = rx;
				wumpusLY = ry;
				has = true;
			}
		}
	}
}

/**************************************************************************
 * Function: setGold 
 * Desc: sets gold 
 * Params: none 
 * Pre: gold not on map 
 * Post: gold is 
 * ***********************************************************************/
void Game::setGold() {

	int rx;
	int ry;
	bool has = false;

	for (int i = 0; i < gold; i++) {
		has = false;
		while (!has) {
			rx = rand() % caveSize;
			ry = rand() % caveSize;		
			char check = rooms[ry][rx]->getEventChar(); 
			if (check == ' ') {	
				rooms[ry][rx]->setEventChar('G');
				rooms[ry][rx]->createPercept();
				goldLY = ry;
				goldLX = rx;
				has = true;
			}
		}
	}
}

/**************************************************************************
 * Function: setPits
 * Desc: sets pits 
 * Params: none 
 * Pre: pits not on map 
 * Post: pits are 
 * ***********************************************************************/
void Game::setPits() {

	int rx;
	int ry;
	bool has;

	for (int i = 0; i < pits; i++) {
		has = false;
		while (!has) {
			rx = rand() % caveSize;
			ry = rand() % caveSize;		
			char check = rooms[ry][rx]->getEventChar(); 
			if (check == ' ') {	
				rooms[ry][rx]->setEventChar('P');
				rooms[ry][rx]->createPercept();
				if (i == 0) {
					pitLX1 = rx;
					pitLY1 = ry;
				}
				if (i == 1) {
					pitLX2 = rx;
					pitLY2 = ry;
				}
				has = true;
			}
		}
	}
}

/**************************************************************************
 * Function: setRope
 * Desc: sets rope and players start location
 * Params: none 
 * Pre: rope not on map 
 * Post: rope is 
 * ***********************************************************************/
void Game::setRope() {

	int rx;
	int ry;
	bool has = false;

	for (int i = 0; i < rope; i++) {
		has = false;
		while (!has) {
			rx = rand() % caveSize;
			ry = rand() % caveSize;		
			char check = rooms[ry][rx]->getEventChar(); 
			if (check == ' ') {	
				rooms[ry][rx]->setEventChar('R');
				rooms[ry][rx]->createPercept();
				rooms[ry][rx]->insertPlayer();
				playerLY = ry;
				playerLX = rx;
				has = true;
			}
		}
	}
}
/**************************************************************************
 * Function: playAgain 
 * Desc: checks if the user wants to play again. This wil return true 
 * 	while the game is still going, and will jump into the switch
 * 	statement once gameOver is flipped to false.
 * Params: none 
 * Pre: gameOver is false 
 * Post: the game is either resumed or exited 
 * ***********************************************************************/
/*
bool Game::playAgain() {

	string input, newInput;	
	char c, nc;
	int dim;

	if (gameOver == true) {
		cout << "Would you like to play again? [y][n]: ";
		getline(cin, input, '\n');	
		c = tolower(input[0]);
		switch (c) {
			case 'y':
				cout << "Would you like to use new dimensions? [y][n]: ";
				getline(cin, newInput, '\n');	
				nc = tolower(newInput[0]);
				switch (nc) {
					case 'y':
						cout << "Enter the new cave dimension: ";
						cin >> dim;	
						rooms.clear();
						createRooms(dim);
					break;
					case 'n':
						rooms.clear();
						createRooms(caveSize);	
					break;
				}	
				reset();
			break;
			case 'n':
				cout << "Goodbye" << endl;
				rooms.clear();
				again = false;
			break;
		}
	} else {
		gameOver = false;
		again = true;
	}
	return again;
}

void Game::reset() {
	gameOver = false;
	goldFound = false;
	foundAndReturned = false;
	killedWumpus = false;
	touchedWumpus = false;
	fellInPit = false;
	arrows = 3;				
	moves = 0;
}
*/
/**************************************************************************
 * Function: isOver 
 * Desc: checks if the wumpus or pits have been reached 
 * Params: none 
 * Pre: player is alive 
 * Post: player is dead 
 * ***********************************************************************/
bool Game::isOver() {
	return gameOver;
}

/**************************************************************************
 * Function: wumpusKilled 
 * Desc: checks if the wumpus is dead 
 * Params: none 
 * Pre: wumpus is alive 
 * Post: wumpus is alive or dead 
 * ***********************************************************************/
bool Game::wumpusKilled() {
	return killedWumpus;
}

/**************************************************************************
 * Function: movePlayer 
 * Desc: Function to control the movement of players
 * Params: none 
 * Pre: player is at location x y 
 * Post: player is at location x+-1 y+-1 
 * ***********************************************************************/
void Game::movePlayer(char dir) {
	//system("clear");
	/* w 119
	// a 97
	// s 115
	   d 100 */

	switch (dir) {
		case 'w':
			if (playerLY - 1 >= 0) {
				playerLY = playerLY - 1;
				rooms[playerLY][playerLX]->insertPlayer();
				rooms[playerLY + 1][playerLX]->removePlayer();
			}
		break;
		case 'a':
			if (playerLX - 1 >= 0) {
				playerLX = playerLX - 1;
				rooms[playerLY][playerLX]->insertPlayer();
				rooms[playerLY][playerLX + 1]->removePlayer();
			}
		break;
		case 's':
			if (playerLY + 1 <= caveSize - 1) {
				playerLY = playerLY + 1;
				rooms[playerLY][playerLX]->insertPlayer();	
				rooms[playerLY - 1][playerLX]->removePlayer();
			}
		break;
		case 'd':
			if (playerLX + 1 <= caveSize - 1) {
				playerLX = playerLX + 1;
				rooms[playerLY][playerLX]->insertPlayer();
				rooms[playerLY][playerLX - 1]->removePlayer();
			}
		break;
	}	
	moves++;
	emitEvents();
	setGameStatus();
	//hasReached(playerLY, playerLX);
}

/**************************************************************************
 * Function: setGameStatus
 * Desc: sets the status of the game 
 * Params: none 
 * Pre: player location exists 
 * Post: player location placed on map 
 * ***********************************************************************/
void Game::setGameStatus() {
	hasReached(playerLY, playerLX);
	if (foundAndReturned) {
		cout << "You Won, game over." << endl;
		gameOver = true;
	} else if (touchedWumpus) {
		cout << "You Lost, game over." << endl;
		gameOver = true;
	} else if (fellInPit) {
		gameOver = true;
	}	
}

/**************************************************************************
 * Function: hasReached 
 * Desc: checks if the thing has been reached with the given locations
 * Params: x and y locations of the calling function 
 * Pre: a thing has not been reached, returning false
 * Post: a thing has or has not been reached, returning true 
 * ***********************************************************************/
void Game::hasReached(int y, int x) {
	//system("clear");
	if ((y == wumpusLY) && (x == wumpusLX)) {
		cout << rooms[y][x]->emitEncounter() << endl;
		touchedWumpus = true;
	}
	if ((y == pitLY1) && (x == pitLX1)) {
		cout << rooms[y][x]->emitEncounter() << endl;
		fellInPit = true;
	}
	if ((y == pitLY2) && (x == pitLX2)) {
		cout << rooms[y][x]->emitEncounter() << endl;
		fellInPit = true;
	}
	if ((y == batLY1) && (x == batLX1)) {
		cout << rooms[y][x]->emitEncounter() << endl;
		batsMovePlayer();
	}
	if ((y == batLY2) && (x == batLX2)) {
		cout << rooms[y][x]->emitEncounter() << endl;
		batsMovePlayer();
	}
	if ((y == goldLY) && (x == goldLX)) {
		cout << rooms[y][x]->emitEncounter() << endl;
		rooms[goldLY][goldLX]->setEventChar(' ');
		goldFound = true;
	}
	if (rooms[y][x]->getEventChar() == 'R' && goldFound) {
		foundAndReturned = true;
	}
}

/**************************************************************************
 * Function: emitEvents 
 * Desc: emits the events based on the player's proximity to other
 * 	objects 
 * Params: none 
 * Pre: player knows where past proximities were 
 * Post: player is updated on proximities after moving 
 * ***********************************************************************/
void Game::emitEvents() {

	if (playerLX-1 >= 0 && rooms[playerLY][playerLX-1]->getEventChar() != ' ') {
		cout << rooms[playerLY][playerLX-1]->emitPercept() << endl;
	}
	if (playerLX+1 < caveSize && rooms[playerLY][playerLX+1]->getEventChar() != ' ') {
		cout << rooms[playerLY][playerLX+1]->emitPercept() << endl;	
	}
	if (playerLY-1 >= 0 && rooms[playerLY-1][playerLX]->getEventChar() != ' ') {
		cout << rooms[playerLY-1][playerLX]->emitPercept() << endl;
	}
	if (playerLY+1 < caveSize && rooms[playerLY+1][playerLX]->getEventChar() != ' ') {
		cout << rooms[playerLY+1][playerLX]->emitPercept() << endl;	
	}
}

/**************************************************************************
 * Function: shootArrow 
 * Desc: shoots the arrow for a max of three spaces in nwse directions 
 * 	Subtracts 1 from the arrow count, until no arrows are left. If
 * 	the arrow hits the wumpus, gameOver sets to true
 * Params: char for direction to shoot 
 * Pre: greater than 0 arrows exist 
 * Post: greater than or equal to 0 
 * ***********************************************************************/
void Game::shootArrow() {

	arrowLX = playerLX;
	arrowLY = playerLY;
	int spaces = 0;
	char dir = shootDirection();

	if (arrows == 0) {
		cout << "You have no arrows left." << endl;
	} else {
		for (int i = 0; i < 3; i++) {
			cout << "Shot arrow " << spaces << " spaces." << endl;
			if (dir == 'w' && arrowLY - 1 >= 0 && killedWumpus == false) {
				arrowLY = arrowLY - 1;
				spaces++;
			}		
			if (dir == 'a' && arrowLX - 1 >= 0 && killedWumpus == false) {
				arrowLX = arrowLX - 1;
				spaces++;
			}
			if (dir == 's' && arrowLY < caveSize && killedWumpus == false) {
				arrowLY = arrowLY + 1;
				spaces++;
			}
			if (dir == 'd' && arrowLX + 1 < caveSize && killedWumpus == false) {
				arrowLX = arrowLX + 1;
				spaces++;
			}
			hasShot(arrowLY, arrowLX);
			if (killedWumpus) { i = 3; break; }
		}
		arrows--;
	}
	cout << "Spaces Shot: " << spaces << endl;
	cout << "Arrows left: " << arrows << endl;
}

/**************************************************************************
 * Function: getPlayerAction 
 * Desc: determines user input for either moving or shooting based on 
 * 	provided character values. If the first character is the space bar,
 * 	prompt the user to enter the direction they'd like to shoot,
 * 	otherwise allow the player to move in the w a s d directions.
 * Params: none 
 * Pre: player is still on map and wumpus is alive and gold has not been
 * 	found. 
 * Post: The player has either moved or shot an arrow, either hitting a 
 * 	target or not. if a target is not hit, move the wumpus to a random
 * 	location for 75% of the time of a missed arrow.  
 * ***********************************************************************/
void Game::getPlayerAction(char action) {
	
	//if (isspace(action)) {
		//shootArrow();
	//} else {
		switch (action) {
			case 'w': 
				movePlayer(action);
			break;
			case 'a':
				movePlayer(action);
			break;
			case 's':
				movePlayer(action);
			break;
			case 'd':
				movePlayer(action);
			break;
			case ' ':
				shootArrow();
			break;
		}
//	}
	//cin.ignore(1, '\n');
}

/**************************************************************************
 * Function: shootDirection() 
 * Desc: prompts player for the w a s d values as integers. 
 * 	does not accept any other values.
 * Params: none 
 * Pre: none 
 * Post: returns the w a s d characters as integer values
 * ***********************************************************************/
char Game::shootDirection() {
	
	string dir;
	cout << "Enter direction to shoot: ";
	getline(cin, dir, '\n');
	switch (dir[0]) {
		case 'w':
			return 'w';
		break;
		case 'a':
			return 'a';
		break;
		case 's':
			return 's';
		break;
		case 'd':
			return 'd';
		break;
	}
}

/**************************************************************************
 * Function: hasShot 
 * Desc: checks if the wumpus has been shot. If it has, user is granted 
 * 	victory and asked to try again. If the arrow misses the wumpus
 *	then there is s 75 percent chance that the wumpus will move to a 
 *	new location on the map.
 * Params: x and y locations of the calling function 
 * Pre: wumpus is alive
 * Post: wumpus is either alive or not 
 * ***********************************************************************/
void Game::hasShot(int y, int x) {
	//system("clear");
	srand(time(NULL));
	int chance = rand() % 4;
	int wy;
	int wx;
	bool wumpusMoved = false;

	if ((y == wumpusLY) && (x == wumpusLX)) {
		cout << "Congratulations, you have killed the Wumpus!" << endl;
		killedWumpus = true;	
		gameOver = true;
	} else {
		killedWumpus = false;
		if (chance != 3) { // could be any number of range 4
			rooms[wumpusLY][wumpusLX]->setEventChar(' ');
			for (int i = 0; i < caveSize * caveSize; i++) {
				while (wumpusMoved == false) {
					wy = rand() % caveSize;
					wx = rand() % caveSize;
					if (rooms[wy][wx]->getEventChar() == ' ') {
						rooms[wy][wx]->setEventChar('W');									
						wumpusMoved = true;
						wumpusLY = wy;
						wumpusLX = wx;
					}
				}
			}
		}				
	}
}

/**************************************************************************
 * Function: batsMovePlayer 
 * Desc: when the player encounters the bats, the player is moved to 
 * 	a random, unchecked location. This location can be an empty room,
 * 	a pit, a location of another bat, or the wumpus. The results
 * 	of enountering the above remains the same. 
 * Params: none 
 * Pre: player is alive
 * Post: player is either alive or not 
 * ***********************************************************************/
void Game::batsMovePlayer() {

	srand(time(NULL));

	int ySaved = playerLY;
	int xSaved = playerLX;
	int py;
	int px;	

	py = rand() % caveSize;
	px = rand() % caveSize;

	rooms[py][px]->insertPlayer();
	rooms[ySaved][xSaved]->removePlayer();

	playerLY = py;
	playerLX = px;

	hasReached(playerLY, playerLX);
}
