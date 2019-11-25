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
		int rope = 1;
		int player = 1;
		int arrows = 3;
		int caveSize;
		bool gameOver;
		bool again;
		bool killedWumpus;
		bool touchedWumpus;
		bool fellInPit;
		bool foundAndReturned;
		bool goldFound;
		int moves = 0;
		vector<vector<Room*> > rooms;

		// Locations
		int arrowLX;
		int arrowLY;

		int goldLX;
		int goldLY;

		int ropeLX;
		int ropeLY;

		int batLX1;
		int batLY1;
		int batLY2;
		int batLX2; 

		int pitLX1;
		int pitLY1;
		int pitLX2;
		int pitLY2;

		int playerLX;
		int playerLY;

		int wumpusLX;
		int wumpusLY;
		
	public:
		Game();
		~Game();
		void createRooms(int);
		void printDevRooms();
		void printProdRooms();
		void printInstructions();
		void setBats();
		void setWumpus();
		void setGold();
		void setPits();
		void setRope();
		void setGameStatus(); // line 360
		bool isOver();
		bool playAgain(); // line 343
		void reset();
		bool wumpusKilled();
		void gfar();

		void movePlayer(char); // line 288
		
		void emitEvents(); // line 297
		void shootArrow(); // line 375
		void hasReached(int,int); // line 391
		void hasShot(int,int);
		void getPlayerAction(char); // line 441
		char shootDirection(); // line 476
		void batsMovePlayer();
};

#endif
