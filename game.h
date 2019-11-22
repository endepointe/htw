/******************************************************************************
 * Filename: Game.h
 * Author: Alvin Johns
 * Date: Nov 19, 2019
 * Desc: Controls the creation of game assets
 * Input: none
 * Output: Per game - 2 bats, 2 pits, 1 Wumpus, 1 Gold stash, Player, 3 Arrows
 * 	player and wumpus location
 * ***************************************************************************/
#ifndef GAME_H
#define GAME_H

#include <vector>
#include "room.h"

using namespace std;

class Game {
	private:
		int bats = 2;
		int pits = 2;
		int wumpus = 1;
		int gold = 1;
		int player = 1;
		int arrows = 3;
		int arrowLocX;
		int arrowLocY;
		int playerLocX;
		int playerLocY;
		int wumpusLocX;
		int wumpusLocY;
		vector<Room> rooms;

	public:
		Game();
		vector<vector<Room*> > createRooms(int);
		void createGrid(int, vector<vector<Room*> >);
		void setCave();
};

#endif
