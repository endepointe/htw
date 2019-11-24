/*****************************************************************************
 * Filename: Pit.cpp
 * Author: Alvin Johns
 * Date: Nov 20, 2019
 * Desc: Class to hold the operations of the pit
 * Input: none
 * Output: event string
 ****************************************************************************/
#include "event.h"
#include "pit.h"
#include <string>
using namespace std;

Pit::Pit() {
	msg = "You feel a breeze.";
}

string Pit::percept() {
	return msg;
}

string Pit::encounter() {
	return "You fell into the pit.";
}
