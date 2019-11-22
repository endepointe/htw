/*****************************************************************************
 * Filename: wumpus.h
 * Author: Alvin Johns
 * Date: Nov 20, 2019
 * Desc: Class to hold the operations of the wumpus
 * Input: none
 * Output: event string
 ****************************************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"
#include <string>
using namespace std;

class Wumpus : public Event {
	private:
		string msg;

	public:
		Wumpus();
		string percept();
};
#endif
