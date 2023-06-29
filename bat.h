
#ifndef BAT_H
#define BAT_H

#include "event.h"
#include <string>
using namespace std;

class Bat : public Event {
	private:
		string msg;

	public:
		Bat();
		string percept();
		string encounter();
};
#endif
