
#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"
#include <string>
using namespace std;

class Wumpus : public Event {
	private:
		string msg;

	public:
		Wumpus();
		string percept();
		string encounter();
};
#endif
