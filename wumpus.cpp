
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
