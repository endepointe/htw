/*****************************************************************************
 * Filename: gold.h
 * Author: Alvin Johns
 * Date: Nov 20, 2019
 * Desc: Class to hold the operations of the gold
 * Input: none
 * Output: event string
 ****************************************************************************/
#ifndef GOLD_H
#define GOLD_H

#include "event.h"
#include <string>
using namespace std;

class Gold : public Event {
	private:
		string msg;

	public:
		Gold();
		string percept();
};
#endif
