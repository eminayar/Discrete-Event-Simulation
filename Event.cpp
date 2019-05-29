//
// Created by muhammed emin ayar on 23/11/2017.
//
#include "Event.h"

Event::Event() {
    this->eventType="NONE";
    this->sortThis=0;
    this->eventTime=0.0;
    this->info1=0;
    this->info2=0;
    this->info3=0;
}

Event::Event( string type, double a, double b, double c, double d , double e ) {
    this->eventType=type;
    this->sortThis=a;
    this->eventTime=b;
    this->info1=c;
    this->info2=d;
    this->info3=e;
}

bool Event::operator>(const Event &scnd) const{
    return this->sortThis>scnd.sortThis;
}

bool Event::operator<(const Event &scnd) const{
    return this->sortThis<scnd.sortThis;
}

Event::~Event() {
}

