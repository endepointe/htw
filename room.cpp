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
 * Desc: Sets default values for a room 
 * Params: None
 * Output: None
 * Pre: None
 * Post: Class params are set to false
 * *************************************************************************/
Room::Room() {
	r_bat = false;
	r_pit = false;
	r_gold = false;
	r_wumpus = false;
}

/****************************************************************************
 * Function: insertBat 
 * Desc: Sets value for bat to true 
 * Params: None
 * Output: None
 * Pre: None
 * Post: true 
 * *************************************************************************/
void Room::insertBat() {
	r_bat = true;
}

/****************************************************************************
 * Function: hasBat 
 * Desc: Returns t or f whether there is a bat 
 * Params: None
 * Output: None
 * Pre: None
 * Post: None 
 * *************************************************************************/
bool Room::hasBat() const {
	return r_bat;
}

/****************************************************************************
 * Function: insertPit 
 * Desc: Sets value of pit to true 
 * Params: None
 * Output: None
 * Pre: None
 * Post: true
 * *************************************************************************/
void Room::insertPit() {
	r_pit = true;
}
	
/****************************************************************************
 * Function: hasPit 
 * Desc: return r of f whether there is a pit in the room 
 * Params: None
 * Output: t or f 
 * Pre: None
 * Post: None 
 * *************************************************************************/	
bool Room::hasPit() const {
	return r_pit;
}

/****************************************************************************
 * Function: insertGold 
 * Desc: Sets value to true 
 * Params: None
 * Output: None
 * Pre: None
 * Post: true 
 * *************************************************************************/
void Room::insertGold() {
	r_gold = true;
}
	
/****************************************************************************
 * Function: hasGold 
 * Desc:  returns whether there is gold in the room 
 * Params: None
 * Output: t or f 
 * Pre: None
 * Post: None 
 * *************************************************************************/	
bool Room::hasGold() const {
	return r_gold;
}
	
/****************************************************************************
 * Function: insertWumpus 
 * Desc: Sets value to true 
 * Params: None
 * Output: None 
 * Pre: None
 * Post: true 
 * *************************************************************************/	
void Room::insertWumpus() {
	r_wumpus = true;
}
	
/****************************************************************************
 * Function: hasWumpus 
 * Desc: return true or false
 * Params: None
 * Output: bool 
 * Pre: None
 * Post: None 
 * *************************************************************************/	
bool Room::hasWumpus() const {
	return r_wumpus;
}

/****************************************************************************
 * Function: percept 
 * Desc: returns a string value given the contents of the room 
 * Params: None
 * Output: 1 0f 4 conditions is true 
 * Pre: None
 * Post: a string is returned 
 * *************************************************************************/
string Room::percept() {

	if (r_bat) {
		return "You hear wings flapping.";
	}	
	
	if (r_pit) {
		return "You feel a breeze.";
	}

	if (r_gold) {
		return "You see a glimmer nearby.";
	}

	if (r_wumpus) {
		return "You smell a terrible stench.";
	}
	
	return "There's nothing in this room.";

}
