
//
// Created by muhammed emin ayar on 23/11/2017.
//

#ifndef PROJECT2_EMINAYAR_CASHIER_H
#define PROJECT2_EMINAYAR_CASHIER_H

#include "Event.h"

class Cashier{
public:
    int numBusy;
    int numQueue,maxnNum;
    int n;
    vector <bool> busy;
    vector <double> busyTime;
    priority_queue < Event , vector <Event> , greater<Event> > cashierQueue;
    Cashier( int num );
    bool empty();
    bool available();
    void done( int which );
    Event takeOrder( double time );
    void addQueue( Event addThis );
};

#endif //PROJECT2_EMINAYAR_CASHIER_H
