
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
