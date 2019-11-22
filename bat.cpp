/*****************************************************************************
 * Filename: bat.cpp
 * Author: Alvin Johns
 * Date: Nov 20, 2019
 * Desc: Class to hold the operations of the bat
 * Input: none
 * Output: event string
 ****************************************************************************/
#include "event.h"
#include "bat.h"
#include <string>
using namespace std;

Bat::Bat() {
	msg = "You hear wings flapping.";
}

string Bat::percept() {
	return msg;
}
