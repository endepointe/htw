/*****************************************************************************
 * Filename: wumpus.cpp
 * Author: Alvin Johns
 * Date: Nov 20, 2019
 * Desc: Class to hold the operations of the wumpus
 * Input: none
 * Output: event string
 ****************************************************************************/
#include "event.h"
#include "wumpus.h"
#include <string>
using namespace std;

Wumpus::Wumpus() {
	msg = "You smell a terrible stench.";
}

string Wumpus::percept() {
	return msg;
}

string Wumpus::encounter() {
	return "You encountered the Wumpus.";
}
