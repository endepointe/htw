
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
