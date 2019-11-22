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
		Wumpus *wumpus;
		Gold *gold;
		Pit *pit;
		Bat *bat;
		Rope *rope;
		
	public:
		Room();
		string emitPercept(); 
		char getEventChar();
		void setEventChar(char);
};
#endif
