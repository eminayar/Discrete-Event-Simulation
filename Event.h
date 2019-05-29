//
// Created by muhammed emin ayar on 23/11/2017.
//

#ifndef PROJECT2_EMINAYAR_EVENT_H
#define PROJECT2_EMINAYAR_EVENT_H

#include <string>
#include <queue>
#include <vector>

using namespace std;

class Event{
public:
    string eventType;
    double sortThis,eventTime,info1,info2,info3;
    Event();
    bool operator >( const Event &scnd) const;
    bool operator <( const Event &scnd) const;
    Event( string type , double a , double b , double c , double d , double e );
    ~Event();
};

#endif //PROJECT2_EMINAYAR_EVENT_H
