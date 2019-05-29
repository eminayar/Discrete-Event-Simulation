//
// Created by muhammed emin ayar on 23/11/2017.
//

#ifndef PROJECT2_EMINAYAR_TIMELINE_H
#define PROJECT2_EMINAYAR_TIMELINE_H

#include "Event.h"

class TimeLine{
public:
    priority_queue <Event , vector <Event> , greater<Event> > timeQueue;
    int numElements,maxNumElements;
    TimeLine();
    void addEvent( Event addThis );
    Event getNext();
    bool empty();
    ~TimeLine();
};

#endif //PROJECT2_EMINAYAR_TIMELINE_H
