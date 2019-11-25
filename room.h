/****************************************************************************
 * Filename: Room.h
 * Author: Alvin Johns
 * Date: Nov 19, 2019
 * Desc: Declaration file for the rooms
 * Input: None
 * Output: None
 * *************************************************************************/
#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "pit.h"
#include "bat.h"
#include "rope.h"
#include <string>

using namespace std;

class Room {

	private:
		Event *event;
		char ec;
		bool playerHere;
		Wumpus *wumpus;
		Gold *gold = nullptr;
		Pit *pit = nullptr;
		Bat *bat = nullptr;
		Rope *rope = nullptr;
		
	public:
		Room();
		~Room();
		void createPercept();
		string emitPercept(); 
		string emitEncounter();
		char getEventChar();
		void setEventChar(char);
		void insertPlayer();
		void removePlayer();
		bool hasPlayer();
};
#endif
