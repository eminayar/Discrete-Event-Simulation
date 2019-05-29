//
// Created by muhammed emin ayar on 23/11/2017.
//
#include <iostream>
#include <algorithm>
#include "TimeLine.h"
#include "Cashier.h"
#include "Barista.h"

using namespace std;

typedef pair <double,double> dd;

int main( int argc , char* argv[] ){

    freopen(argv[1] , "r" , stdin );
    freopen(argv[2] , "w" , stdout );

    int N,M;
    scanf(" %d %d",&N,&M);
    TimeLine firstModel,secondModel;
    Cashier firstCashiers(N),secondCashiers(N);
    vector <Barista> makers;
    vector <dd> turnaround;
    makers.push_back( Barista( N/3 ) );
    for( int i=1 ; i<=M ; i++ ){
        double a,b,c,d;
        scanf(" %lf %lf %lf %lf",&a,&b,&c,&d);
        firstModel.addEvent( Event( "arrival" , a , a , b , c , d ) );
        secondModel.addEvent( Event( "arrival" , a , a , b , c , d ) );
    }

    double runningTime=0;

    while( !firstModel.empty() ){
        Event a=firstModel.getNext();
        runningTime=a.sortThis;
        if( a.eventType=="arrival" )
            firstCashiers.addQueue( a );
        if( a.eventType=="orderDone" ){
            firstCashiers.done( (int)a.info1 );
            makers[0].addQueue( Event( "dummytext" , a.info3 , a.eventTime , a.info1 , a.info2 , a.info3 ) );
        }
        if( a.eventType=="coffeeDone"){
            makers[0].done( (int)a.info2 );
            turnaround.push_back( dd( a.eventTime , a.sortThis ) );
        }
        while( !firstCashiers.empty() && firstCashiers.available() ){
            Event info=firstCashiers.takeOrder( a.sortThis );
            firstModel.addEvent( info );
        }
        while( !makers[0].empty() && makers[0].available() ){
            Event info=makers[0].makeCoffee( a.sortThis );
            firstModel.addEvent( info );
        }
    }

    printf("%.2lf\n",runningTime);
    printf("%d\n",firstCashiers.maxnNum);
    printf("%d\n",makers[0].maxNum);
    for( int i=1 ; i<=N ; i++ ) printf("%.2lf\n",firstCashiers.busyTime[i]/runningTime);
    for( int i=1 ; i<=N/3 ; i++ ) printf("%.2lf\n",makers[0].busyTime[i]/runningTime);
    sort( turnaround.begin() , turnaround.end() );
    for( int i=0 ; i<(int)turnaround.size(); i++ ) printf("%.2lf\n",turnaround[i].second-turnaround[i].first);

    puts("");

    turnaround.clear();
    for( int i=1 ; i<=N/3 ; i++ ) makers.push_back( Barista(1) );

    while( !secondModel.empty() ){
        Event a=secondModel.getNext();
        runningTime=a.sortThis;
        if( a.eventType=="arrival" )
            secondCashiers.addQueue( a );
        if( a.eventType=="orderDone" ){
            int x=(int)a.info1;
            secondCashiers.done( x );
            makers[(x+2)/3].addQueue( Event( "dummytext" , a.info3 , a.eventTime , a.info1 , a.info2 , a.info3 ) );
        }
        if( a.eventType=="coffeeDone" ){
            int x=(int)a.info1;
            makers[(x+2)/3].done( a.info2 );
            turnaround.push_back( dd( a.eventTime , a.sortThis ) );
        }
        while( !secondCashiers.empty() && secondCashiers.available() ){
            Event info=secondCashiers.takeOrder( a.sortThis );
            secondModel.addEvent( info );
        }
        for( int mask=1 ; mask<=N/3 ; mask++ ){
            while( !makers[mask].empty() && makers[mask].available() ){
                Event info=makers[mask].makeCoffee( a.sortThis );
                secondModel.addEvent( info );
            }
        }
    }

    printf("%.2lf\n",runningTime);
    printf("%d\n",secondCashiers.maxnNum);
    for( int i=1 ; i<=N/3 ; i++ ) printf("%d\n",makers[i].maxNum);
    for( int i=1 ; i<=N ; i++ ) printf("%.2lf\n",secondCashiers.busyTime[i]/runningTime);
    for( int i=1 ; i<=N/3 ; i++ ) printf("%.2lf\n",makers[i].busyTime[1]/runningTime);
    sort( turnaround.begin() , turnaround.end() );

    for( int i=0 ; i<(int) turnaround.size() ; i++ )
        printf("%.2lf\n",turnaround[i].second-turnaround[i].first);


    return 0;
}
