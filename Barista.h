//
// Created by muhammed emin ayar on 23/11/2017.
//

#ifndef PROJECT2_EMINAYAR_BARISTA_H
#define PROJECT2_EMINAYAR_BARISTA_H

#include "Event.h"

class Barista{
public:
    int n;
    int numBusy;
    int numQueue,maxNum;
    vector <bool> busy;
    vector <double> busyTime;
    priority_queue <Event> baristaQueue;
    Barista( int num );
    bool empty();
    bool available();
    void done( int num );
    Event makeCoffee( double time );
    void addQueue( Event addThis );
};

#endif //PROJECT2_EMINAYAR_BARISTA_H
