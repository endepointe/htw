
#ifndef PIT_H
#define PIT_H

#include "event.h"
#include <string>
using namespace std;

class Pit : public Event {
	private:
		string msg;

	public:
		Pit();
		string percept();
		string encounter();
};
#endif
