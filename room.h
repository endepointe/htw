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
#include <string>

using namespace std;

class Room : public Event {

	private:
		bool r_bat;
		bool r_pit;
		bool r_gold;
		bool r_wumpus;	
		
	public:
		Room();
		void insertBat();
		bool hasBat() const;
		void insertPit();
		bool hasPit() const;
		void insertGold();
		bool hasGold() const;
		void insertWumpus();
		bool hasWumpus() const;
		string percept(); 
};
#endif
