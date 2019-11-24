/******************************************************************************
 * Filename: Game.cpp
 * Author: Alvin Johns
 * Date: Nov 19, 2019
 * Desc: Controls the creation of game assets
 * Input: none
 * Output: Per game - 2 bats, 2 pits, 1 Wumpus, 1 Gold stash, Player, 3 Arrows
 * 	player and wumpus location
 * ***************************************************************************/
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
	setPlayer();
//*/
}

/**************************************************************************
 * Function: printRooms 
 * Desc: creates a grid of specific size with a vector
 * Params: int 
 * Pre: a grid doesnt exist
 * Post: a grid is filled with vector
 * ***********************************************************************/
void Game::printRooms() {

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
			newChar = rooms[i][j]->getEventChar();
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
				playerLY = ry;
				playerLX = rx;
				has = true;
			}
		}
	}
}

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
				rooms[playerLY + 1][playerLX]->setEventChar(' ');
			}
		break;
		case 'a':
			if (playerLX - 1 >= 0) {
				playerLX = playerLX - 1;
				rooms[playerLY][playerLX + 1]->setEventChar(' ');
			}
		break;
		case 's':
			if (playerLY + 1 <= caveSize - 1) {
				playerLY = playerLY + 1;
				rooms[playerLY - 1][playerLX]->setEventChar(' ');
			}
		break;
		case 'd':
			if (playerLX + 1 <= caveSize - 1) {
				playerLX = playerLX + 1;
				rooms[playerLY][playerLX - 1]->setEventChar(' ');
			}
		break;
	}	
	moves++;
	setPlayer();
}

/**************************************************************************
 * Function: setPlayer
 * Desc: sets player on map 
 * Params: none 
 * Pre: player location exists 
 * Post: player location placed on map 
 * ***********************************************************************/
void Game::setPlayer() {

	gameOver = hasReached(playerLY, playerLX);
	if (gameOver) {
		cout << "game over" << endl;
	} else {
		rooms[playerLY][playerLX]->setEventChar('*');
		emitEvents();
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

	/* w 119
	// a 97
	// s 115
	   d 100 */

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
 * Function: hasReached 
 * Desc: checks if the thing has been reached with the given locations
 * Params: x and y locations of the calling function 
 * Pre: a thing has not been reached, returning false
 * Post: a thing has or has not been reached, returning true 
 * ***********************************************************************/
bool Game::hasReached(int y, int x) {
	//system("clear");
	if ((y == wumpusLY) && (x == wumpusLX)) {
		cout << rooms[y][x]->emitEncounter() << endl;
		return true;
	}
	if ((y == pitLY1) && (x == pitLX1)) {
		cout << rooms[y][x]->emitEncounter() << endl;
		return true;	
	}
	if ((y == pitLY2) && (x == pitLX2)) {
		cout << rooms[y][x]->emitEncounter() << endl;
		return true;	
	}
	if ((y == goldLY) && (x == goldLX)) {
		cout << rooms[y][x]->emitEncounter() << endl;
		if (rooms[x][y]->getEventChar() == 'R') {
			cout << rooms[x][y]->emitPercept();
			return true;
		}
	}
	// must check for start of game
	if (rooms[x][y]->getEventChar() == 'R' && moves > 0) {
		cout << rooms[x][y]->emitPercept();
		return true;
	} else { return false; }
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
 * 	victory and asked to try again. 
 * Params: x and y locations of the calling function 
 * Pre: wumpus is alive
 * Post: wumpus is either alive or not 
 * ***********************************************************************/
void Game::hasShot(int y, int x) {
	//system("clear");
	if ((y == wumpusLY) && (x == wumpusLX)) {
		cout << "Congratulations, you have killed the Wumpus!" << endl;
		killedWumpus = true;	
		gameOver = true;
	} else {
		killedWumpus = false;
	}
}
