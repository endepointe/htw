
#ifndef GOLD_H
#define GOLD_H

#include "event.h"
#include <string>
using namespace std;

class Gold : public Event {
	private:
		string msg;

	public:
		Gold();
		string percept();
		string encounter();
};
#endif
