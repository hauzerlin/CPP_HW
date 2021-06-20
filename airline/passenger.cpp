#include <iostream>
#include <string>
#include "passenger.h"

using namespace std;

//void passenger::add_passenger(list &l);
//void set_passenger(string);
void passenger::display_data()
{
    cout<<"Record Locator: "<<record<<endl;
    display_name();
    cout<<"DOB: "<< DOB <<endl;
    cout<<"passport number: "<< passport_num <<endl;
    cout<<"Seat Type/Num: ";
    if(type == 1)cout<<"First/";
    else cout<<"economy/";
    cout<<seat_num<<endl;
}

void passenger::display_name()
{
    cout<< first_name <<" ";
    cout<< last_name <<endl;
}

void passenger::set_first(string first)
{
    first_name = first;
}

void passenger::set_last(string last)
{
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

void passenger::set_record(short rd)
{
    record = rd;
}

/*passenger::passenger(string first, string last)
{
    first_name = first;
    last_name = last;
}*/



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

