/*****************************************************************************
 * Filename: bat.h
 * Author: Alvin Johns
 * Date: Nov 20, 2019
 * Desc: Class to hold the operations of the bat
 * Input: none
 * Output: event string
 ****************************************************************************/
#ifndef BAT_H
#define BAT_H

#include "event.h"
#include <string>
using namespace std;

class Bat : public Event {
	private:
		string msg;

	public:
		Bat();
		string percept();
		string encounter();
};
#endif
