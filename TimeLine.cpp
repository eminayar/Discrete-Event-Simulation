#include "TimeLine.h"
TimeLine::TimeLine(){
	this->numElements=0;
	this->maxNumElements=0;
}

void TimeLine::addEvent(Event addThis) {
	timeQueue.push( addThis );
	this->numElements++;
	if( this->numElements > this->maxNumElements ) this->maxNumElements=this->numElements;
}

Event TimeLine::getNext() {
	if( this->numElements == 0 ) return Event();
	this->numElements--;
	Event ret=this->timeQueue.top();
	this->timeQueue.pop();
	return ret;
}

bool TimeLine::empty() {
    return this->numElements == 0;
}

TimeLine::~TimeLine() {
}