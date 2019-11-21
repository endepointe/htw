/******************************************************************************
 * Filename: Event.h
 * Author: Alvin Johns
 * Date: Nov 19, 2019
 * Desc: Declaration file for the virtual events
 * Input: None
 * Output: None
 * ***************************************************************************/
#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

class Event {

	private:
		//		
	public:
		virtual string percept() = 0;
};
#endif
