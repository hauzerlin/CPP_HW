#include <iostream>
#include <string>
#include "passenger.h"

using namespace std;

//void passenger::add_passenger(list &l);
//void set_passenger(string);
void passenger::display_data()
{
    cout<<"DOB: "<< DOB <<endl;
    cout<<"passport number: "<< passport_num <<endl;
    cout<<"Seat type: "<< type <<endl;
    cout<<"Seat number: "<< seat_num <<endl;
}

void passenger::display_name()
{
    cout<< first_name <<" ";
    cout<< last_name <<endl;
}

void passenger::set_name(string first, string last)
{
    first_name = first;
    last_name = last;
}

void passenger::set_DOB(int dob)
{
    DOB = dob;
}

void passenger::set_passport_num(long  ps_num)
{
    passport_num = ps_num;
}

void passenger::set_type(short tp)
{
    type = tp;
}

void passenger::set_seat(short seat)
{
    seat_num = seat;
}

passenger::passenger(string first, string last)
{
    first_name = first;
    last_name = last;
}



/*void passenger::add_passenger(list &l)
{
    passenger *psg = new passenger;
    psg->next = NULL;
    if(l.first == NULL)
    {
        l.first = l.rear = psg;
    }
    else
    {
        psg->preverous = l.rear;
        l.rear->next = psg;
        l.rear = psg;
    }
    l.psg_num++;
}*/

/*void set_first(string first)
{
    passenger.first_name = first;
    //passenger.last_name = last;
    //passenger.DOB = dob;
    //passenger.passport_num = pass_num;
    //passenger.type = type;
}*/

