
#ifndef ROPE_H
#define ROPE_H

#include "event.h"
#include <string>
using namespace std;

class Rope : public Event {
	private:
		string msg;

	public:
		Rope();
		string percept();
		string encounter();
};
#endif
