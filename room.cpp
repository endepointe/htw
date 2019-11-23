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
	return this->ec;
}

/****************************************************************************
 * Function: createPercept 
 * Desc: Creates the percept
 * Params: None
 * Output: None
 * Pre: None
 * Post: None, yet 
 * *************************************************************************/
void Room::createPercept() {

	switch (ec) {
		case 'W':
			wumpus = new Wumpus;
		break;
		case 'R':
			rope = new Rope;
		break;
		case 'B':
			bat = new Bat;
		break;
		case 'P':
			pit = new Pit;
		break;
		case 'G':
			gold = new Gold;
		break;
	}
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
		case 'W':
			return wumpus->percept();	
		break;
		case 'R':
			return rope->percept();	
		break;
		case 'B':
			return bat->percept();	
		break;
		case 'P':
			return pit->percept();	
		break;
		case 'G':
			return gold->percept();	
		break;
	}	

	return "Empty...";
}
