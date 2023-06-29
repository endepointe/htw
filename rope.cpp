
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

string Rope::encounter() {
	return "You found the rope.";
}
