#ifndef IsTime_h 
#define IsTime_h

#include "Arduino.h"

class IsTime
{
	public:
		IsTime();
    	void add(String target, int interval);
    	bool isOver(String target);
	private:
		int _itemsCounter;
};

#endif
