/*****************************************************************************
 * Filename: rope.h
 * Author: Alvin Johns
 * Date: Nov 20, 2019
 * Desc: Class to hold the operations of the rope
 * Input: none
 * Output: event string
 ****************************************************************************/
#ifndef ROPE_H
#define ROPE_H

#include "event.h"
#include <string>
using namespace std;

class Rope : public Event {
	private:
		string msg;

	public:
		Rope();
		string percept();
};
#endif
