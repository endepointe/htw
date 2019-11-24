/*****************************************************************************
 * Filename: gold.cpp
 * Author: Alvin Johns
 * Date: Nov 20, 2019
 * Desc: Class to hold the operations of the gold
 * Input: none
 * Output: event string
 ****************************************************************************/
#include "event.h"
#include "gold.h"
#include <string>
using namespace std;

Gold::Gold() {
	msg = "You see a glimmer nearby.";
}

string Gold::percept() {
	return msg;
}

string Gold::encounter() {
	return "You have the gold.";
}
