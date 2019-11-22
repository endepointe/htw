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
/*
		int bats = 2;
		int pits = 2;
		int wumpus = 1;
		int gold = 1;
		int player = 1;
		int arrows = 3;
		int playerLocX;
		int playerLocY;
		int wumpusLocX;
		int wumpusLocY;
		vector<Room> rooms;
*/

/******************************************************************************
 * Function: Game constructor
 * Desc: Controls the creation of game assets
 * Params: grid count that forms an X x Y grid (e.g. - 4 x 4)
 * Pre: rooms do no exist
 * Post: rooms are created 
 * ***************************************************************************/
Game::Game() {
	/*
	for (int r = 0; r < size; r++) {
		vector<Room*> row;
		for (int col = 0; col < size; col++) {
			row.push_back(new Room);	
		}
	}	
	*/
}

/**************************************************************************
 * Function: createRooms
 * Desc: creates the rooms of type vector
 * Params: int 
 * Pre: a grid doesnt exist
 * Post: a grid is filled with vector
 * ***********************************************************************/
vector<vector<Room*> > Game::createRooms(int count) {

	vector<vector<Room*> > cave;

	for (int i = 0; i < count ;i++) {
	
		vector<Room*> row; 

		for (int j = 0; j < count; j++) {
	
			row.push_back(new Room);
		}			

		cave.push_back(row);
	}
	
	return cave;
}

/**************************************************************************
 * Function: createGrid
 * Desc: creates a grid of specific size with a vector
 * Params: int 
 * Pre: a grid doesnt exist
 * Post: a grid is filled with vector
 * ***********************************************************************/
void Game::createGrid(int xy, vector<vector<Room* > > rooms) {

	int row = xy;
	int col = xy;
	char g = 'G';

	vector<char> ceil = {'+', '-', '-', '-'};
	vector<char> wall = {'|',' ', g,' '};

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
			for (char it : ceil) {
				cout << it;
			}	
		}

		cout << "+" << endl;
		
		for (int j = 0; j < col; j++) {

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
 * Function: setCave 
 * Desc: sets the event within each room
 * Params: none 
 * Pre: an event doesnt exist 
 * Post: a grid is filled with events 
 * ***********************************************************************/
