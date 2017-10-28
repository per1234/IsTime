#include "IsTime.h"
#include "Arduino.h"

#define IS_TIME_LIST_LIMIT 100

typedef struct
{
	String target;
	int interval;
	long next;
} TargetTime;

TargetTime _timeList[IS_TIME_LIST_LIMIT];
int _itemsCounter;

IsTime::IsTime() 
{
	_itemsCounter = 0;
}

void IsTime::add(String target, int interval)
{
	TargetTime item;
	item.target = target;
	item.interval = interval;
	item.next = 0;

	_timeList[_itemsCounter++] = item;

	Serial.print("IsTime. Items in list: ");
	Serial.println(_itemsCounter);
}

bool IsTime::isOver(String target)
{
	long now = micros();

	for (int i = 0; i <= _itemsCounter; i++)	{
    	TargetTime t = _timeList[i];
    	if (target == t.target && now > t.next) {
    		t.next = now + t.interval;
    		_timeList[i] = t;
    		
    		return true;
    	}
    }

	return false;
}
