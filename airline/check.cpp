#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <conio.h>
#include "passenger.h"

using namespace std;

bool first_full(bool seats[])
{
    for(int i=0;i<4;i++)
    {
        if(seats[i])continue;
        return false;
    }
    return true;
}

bool economy_full(bool seats[])
{
    for(int i=4;i<10;i++)
    {
        if(seats[i])continue;
        return false;
    }
    return true;
}

bool record_full(bool record[])
{
    for(int i=0;i<10;i++)
    {
        if(record[i])continue;
        return false;
    }
    return true;
}

void assign_first(passenger* ptr,bool seats[])
{
    short tmp;
    
    srand(time(0));

    while(tmp = (rand()%4)+1)
    {
        if(seats[tmp-1])continue;
        else break;
    }
    ptr->set_seat(tmp);
    seats[tmp-1]=true;
}

void assign_economy(passenger *ptr, bool seats[])
{
    short tmp;
    srand(time(0));

    while(tmp = (rand()%6)+5)
    {
        if(seats[tmp-1])continue;
        else break;
    }
    ptr->set_seat(tmp);
    seats[tmp-1]=true;
}

void assign_record(passenger*ptr, bool record[])
{
    short tmp;
    srand(time(0));

    while(tmp = ((rand()%10)+1))
    {
        if(record[tmp-1])continue;
        else break;
    }
    ptr->set_record(tmp);
    record[tmp-1]=true;
}

int ask_change(int switch_to)
{
    char choose;
    switch (switch_to)
    {
    case 1:
        cerr<<"The economy class seat is full."<<endl;
        cerr<<"But first class is still available.Would you like to change seat to first class?(Y/N)";
        while(cin>>choose)
        {

            if(choose=='Y'||choose=='y')return 1;
            else if(choose=='N'||choose=='n')return 0;
            else continue;
        }
        break;
    
    case 2:
    cerr<<"The first class seat is full."<<endl;
        cerr<<"But economy class is still available.Would you like to change seat to economy class?(Y/N)";
        while(cin>>choose)
        {

            if(choose=='Y'||choose=='y')return 1;
            else if(choose=='N'||choose=='n')return 0;
            else continue;
        }
        break;
    }
    return -1;
}