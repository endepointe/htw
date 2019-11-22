/*****************************************************************************
 * Filename: rope.cpp
 * Author: Alvin Johns
 * Date: Nov 20, 2019
 * Desc: Class to hold the operations of the rope
 * Input: none
 * Output: event string
 ****************************************************************************/
#include "event.h"
#include "rope.h"
#include <string>
using namespace std;

Rope::Rope() {
	msg = "Freedom is close.";
}

string Rope::percept() {
	return msg;
}
