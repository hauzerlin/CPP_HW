#include <iostream>
#include <string>
#include <conio.h>
#include "passenger.h"

using namespace std;

//void list::Push(list &ls);
//void passenger::add_passenger(list &l);
//void set_passenger(string);
void passenger::display_data()
{
    cout<<"Record Locator: "<<record<<endl;
    cout<<"Name: "<<first_name<<" "<<last_name<<endl;
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

void list::init()
{
    first = rear = NULL;
    psg_num = 0;
}

void list::POP(passenger* d_psg)
{
    passenger *save;

    if(d_psg==first && psg_num==1)
    {
        first = rear = NULL;
        psg_num=0;
    }
    else if(d_psg==first)
    {
        save = d_psg->next;
        save->preverous = NULL;
        first = save;
        psg_num--;
    }
    else if(d_psg==rear)
    {
        save = rear->preverous;
        save->next = NULL;
        save = rear;
        psg_num--;
    }
    else
    {
        save = d_psg->next;
        save->preverous = d_psg->preverous;
        save = d_psg->preverous;
        save->next = d_psg->next;
        psg_num--;
    }

}

void list::Push(passenger *psg)
{
    //passenger *psg = new passenger;
    //n->data = v;
    psg->next = NULL;
    psg->preverous = NULL;
    if(first == NULL)    //queue是空的
    {
        first = rear = psg;
    }
    else
    {
        psg->preverous = rear;
        rear->next = psg;      //先將尾巴接上去
        rear = psg;            //再將queue的尾巴移到正確位置
    }
    psg_num++;
}

void list::Display_list()//print all passenger information.
{
    passenger *psg = first;
    for (int i = 0; i<psg_num; i++)
    {

        psg->display_data();
        psg = psg->next;
        cout<<"\n\n";

    }
    getch();
}

bool list::exist(short rd)//use record number to search list if passenger in or not.
{
    passenger *ptr=first;
    for(int i=0;i<psg_num;i++,ptr=ptr->next)
    {
        if(ptr->record != rd)continue;
        else return true;
    }
    return false;
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

