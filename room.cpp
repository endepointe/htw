/****************************************************************************
 * Filename: Room.cpp
 * Author: Alvin Johns
 * Date: Nov 19, 2019
 * Desc: Declaration file for the rooms
 * Input: None
 * Output: None
 * *************************************************************************/
#include "room.h"
#include <string>
using namespace std;

/****************************************************************************
 * Function: Room constructor
 * Desc: Sets default value for the event character
 * Params: None
 * Output: None
 * Pre: None
 * Post: None, yet 
 * *************************************************************************/
Room::Room() {
	srand(time(NULL));
	ec = ' ';
}
/****************************************************************************
 * Function: setEventChar 
 * Desc: Sets the event of the room
 * Params: A char of either 'w' 'g' 'p' 'r' 'b' '.' 
 * Output: None
 * Pre: None
 * Post: None, yet 
 * *************************************************************************/
void Room::setEventChar(char re) {
	ec = re;
}

/****************************************************************************
 * Function: getEventChar
 * Desc: Returns the specified event character
 * Params: None
 * Output: None
 * Pre: None
 * Post: None, yet 
 * *************************************************************************/
char Room::getEventChar() {
	return ec;
}

/****************************************************************************
 * Function: emitPercept 
 * Desc: Emits the event if the event is located at 
 * 	player[loc +/- 1][loc +/- 1]
 * Params: None
 * Output: None
 * Pre: None
 * Post: None, yet 
 * *************************************************************************/
string Room::emitPercept() {

	switch (ec) {
		case 'w':
			wumpus = new Wumpus;
			return wumpus->percept();	
		break;
		case 'r':
			rope = new Rope;
			return rope->percept();	
		break;
		case 'b':
			bat = new Bat;
			return bat->percept();	
		break;
		case 'p':
			pit = new Pit;
			return pit->percept();	
		break;
		case 'g':
			gold = new Gold;
			return gold->percept();	
		break;
	}	

	return "Empty...";

}

