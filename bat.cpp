
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

string Bat::encounter() {
	return "You found a bat.";
}
