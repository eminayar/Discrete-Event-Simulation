//
// Created by muhammed emin ayar on 23/11/2017.
//
#include "Barista.h"

Barista::Barista(int num) {
    this->busy.push_back( true );
    for( int i=1 ; i<=num ; i++ ) this->busy.push_back( false );
    for( int i=0 ; i<=num ; i++ ) this->busyTime.push_back( 0.0 );
    this->n=num;
    this->numBusy=0;
    this->numQueue=0;
    this->maxNum=0;
}

void Barista::addQueue(Event addThis) {
    this->numQueue++;
    if( this->numQueue > this->maxNum ) this->maxNum=this->numQueue;
    this->baristaQueue.push( addThis );
}

bool Barista::empty() {
    return this->numQueue == 0;
}

bool Barista::available() {
    return this->numBusy < this->n;
}

Event Barista::makeCoffee( double time ) {
    Event curr=this->baristaQueue.top();
    this->baristaQueue.pop();
    this->numQueue--;
    Event ret;
    for( int i=1 ; i<=this->n ; i++ ) if( !busy[i] ){
            this->busy[i]=true;
            this->busyTime[i]+=curr.info2;
            this->numBusy++;
            ret=Event( "coffeeDone" , time+curr.info2 , curr.eventTime , curr.info1 , i , i );
            break;
        }
    return ret;
}

void Barista::done(int num) {
    this->numBusy--;
    this->busy[num]=false;
}