//
// Created by muhammed emin ayar on 23/11/2017.
//
#include "Cashier.h"

Cashier::Cashier(int num) {
    this->busy.push_back( true );
    for( int i=1 ; i<=num ; i++ ) this->busy.push_back( false );
    for( int i=0 ; i<=num ; i++ ) this->busyTime.push_back( 0.0 );
    this->n=num;
    this->numBusy=0;
    this->numQueue=0;
    this->maxnNum=0;
}

bool Cashier::empty() {
    return this->numQueue == 0;
}

bool Cashier::available() {
    return this->numBusy < this->n;
}

void Cashier::done( int which ) {
    this->numBusy--;
    this->busy[which]=false;
}

Event Cashier::takeOrder( double time ) {
    Event curr=this->cashierQueue.top();
    this->cashierQueue.pop();
    this->numQueue--;
    Event ret;
    for( int i=1 ; i<=this->n ; i++ ) if( !busy[i] ){
            this->busy[i]=true;
            this->numBusy++;
            this->busyTime[i]+=curr.info1;
            ret=Event( "orderDone" , time+curr.info1 , curr.eventTime , i  , curr.info2 , curr.info3 );
            break;
        }
    return ret;
}

void Cashier::addQueue(Event addThis) {
    this->numQueue++;
    if( this->numQueue > this->maxnNum ) this->maxnNum=this->numQueue;
    this->cashierQueue.push( addThis );
}


