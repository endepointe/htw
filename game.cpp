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
	// create rooms will set the caveSize
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
	cout << "rooms value at [4][2]:" << rooms[caveSize - 1][caveSize - 2]->getEventChar() << endl;
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

	cout << rooms[wumpusLY][wumpusLX]->getEventChar() << endl;
	cout << wumpusLY << wumpusLX << endl;

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
				cout << "\ncreation of bat: ";
				cout << rooms[ry][rx]->getEventChar() << endl;
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
				x = rx;
				y = ry;
				has = true;
			}
		}
	}
	cout << "wumpus loc y x: " << y << " " << x << rooms[y][x]->getEventChar() << endl;
	cout << "random location: " << rooms[caveSize - 1][caveSize - 1]->getEventChar() << endl;
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
 * Function: movePlayer 
 * Desc: Function to control the movement of players
 * Params: none 
 * Pre: player is at location x y 
 * Post: player is at location x+-1 y+-1 
 * ***********************************************************************/
void Game::movePlayer(char dir) {

	switch (dir) {
		case 'w':
			if (playerLY - 1 < 0) {
	 			cout << "You cannot move further" << endl;
			} else {
				playerLY = playerLY - 1;
				rooms[playerLY + 1][playerLX]->setEventChar(' ');
			}
		break;
		case 'a':
			if (playerLX - 1 < 0) {
	 			cout << "You cannot move further" << endl;
			} else {
				playerLX = playerLX - 1;
				rooms[playerLY][playerLX + 1]->setEventChar(' ');
			}
		break;
		case 's':
			if (playerLY + 1 > caveSize - 1) {
	 			cout << "You cannot move further" << endl;
			} else {
				playerLY = playerLY + 1;
				rooms[playerLY - 1][playerLX]->setEventChar(' ');
			}
		break;
		case 'd':
			if (playerLX + 1 > caveSize + 1) {
	 			cout << "You cannot move further" << endl;
			} else {
				playerLX = playerLX + 1;
				rooms[playerLY][playerLX - 1]->setEventChar(' ');
			}
		break;
	}	
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
	rooms[playerLY][playerLX]->setEventChar('*');
	emitEvents();
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
	if ((goldLY - 1 == playerLY) || (goldLY + 1 == playerLY )) {
		rooms[goldLY][goldLX]->emitPercept();
	}
}
