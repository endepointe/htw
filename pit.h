/*****************************************************************************
 * Filename: pit.h
 * Author: Alvin Johns
 * Date: Nov 20, 2019
 * Desc: Class to hold the operations of the pit
 * Input: none
 * Output: event string
 ****************************************************************************/
#ifndef PIT_H
#define PIT_H

#include "event.h"
#include <string>
using namespace std;

class Pit : public Event {
	private:
		string msg;

	public:
		Pit();
		string percept();
		string encounter();
};
#endif
