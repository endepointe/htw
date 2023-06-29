
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
	playerHere = false;
}

Room::~Room() {
///*	
	//if (ec == 'W') {
		delete wumpus;	
	//}
	//if (ec == 'B') {
		delete bat;
	//}
	//if (ec == 'R') {
		delete rope;	
	//}
	//if (ec == 'P') {
		delete pit;	
	//}
//	if (ec == 'G') {
		delete gold;	
//	}
//*/	
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
	return "";
}

/****************************************************************************
 * Function: emitEncounter 
 * Desc: Emits the encounter event if the event is located at 
 * 	player[loc +/- 1][loc +/- 1]
 * Params: None
 * Output: None
 * Pre: None
 * Post: None, yet 
 * *************************************************************************/
string Room::emitEncounter() {

	switch (ec) {
		case 'W':
			return wumpus->encounter();	
		break;
		case 'R':
			return rope->encounter();	
		break;
		case 'B':
			return bat->encounter();	
		break;
		case 'P':
			return pit->encounter();	
		break;
		case 'G':
			return gold->encounter();	
		break;
	}	
	return "";
}

/****************************************************************************
 * Function: insertPlayer 
 * Desc: instead of setting the event character for the player location,
 * 	flips the hasPlayer to true
 * Params: None
 * Output: None
 * Pre: None
 * Post: player is on map 
 * *************************************************************************/
void Room::insertPlayer() {
	playerHere = true;
}

/****************************************************************************
 * Function: removePlayer 
 * Desc: flips the hasPlayer to false after moving from a room
 * Params: None
 * Output: None
 * Pre: hasPlayer is true 
 * Post: hasPlayer is false 
 * *************************************************************************/
void Room::removePlayer() {
	playerHere = false;
}

/****************************************************************************
 * Function: hasPlayer 
 * Desc: returns whether the player is in room or not 
 * Params: None
 * Output: None
 * Pre: none
 * Post: none 
 * *************************************************************************/
bool Room::hasPlayer() {
	return playerHere;
}
