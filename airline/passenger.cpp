#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "passenger.h"

using namespace std;

//passenger class's function
void passenger::display_data()
{
    cout<<"Record Locator: "<<record<<endl;
    cout<<"Name: "<<first_name<<" "<<last_name<<endl;
    cout<<"DOB: "<< DOB <<endl;
    cout<<"passport number: "<< passport_num <<endl;
    cout<<"Seat Type/Num: ";
    if(type == 1)cout<<"First/";
    else cout<<"Economy/";
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

int passenger::return_dob()
{return DOB;}

void passenger::set_passport_num(long  ps_num)
{
    passport_num = ps_num;
}

long passenger::return_passport_num()
{return passport_num;}

void passenger::set_type(short tp)
{
    type = tp;
}

short passenger::return_type()
{return type;}

void passenger::set_seat(short seat)
{
    seat_num = seat;
}

short passenger::return_seat_num()
{return seat_num;}

void passenger::set_record(short rd)
{
    record = rd;
}


//list class's function
void list::init()
{
    first = rear = NULL;
    psg_num = 0;
}

void list::POP(passenger* const d_psg)
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

    delete d_psg;
}

void list::Push(passenger *psg)
{
    //passenger *psg = new passenger;
    //n->data = v;
    psg->next = NULL;
    psg->preverous = NULL;
    if(first == NULL)    //list是空的
    {
        first = rear = psg;
    }
    else
    {
        psg->preverous = rear;
        rear->next = psg;      //先將尾巴接上去
        rear = psg;            //再將list的尾巴移到正確位置
    }
    psg_num++;
}

void list::Display_list()//print all passenger information.
{
    passenger *psg = first;//locate ptr to target passenger
    for (int i = 0; i<psg_num; i++)
    {

        psg->display_data();
        psg = psg->next;
        cout<<"\n\n";

    }
    getch();
}

void list::boarding_pass(short rd)
{
    //search list and locate the ptr on target passenger.
    passenger *ptr=first;
    for(int i=1;i<psg_num;i++,ptr=ptr->next)
    {
        if(ptr->record!=rd)continue;
        break;
    }

    //Print out the Boarding Pass for record
    for(int i=0;i<55;i++)cout<<"*";
    cout<<"\n*                    Boarding Pass                    *"<<endl;
    cout<<"*Name: "<<setw(47)<<left<<((ptr->first_name)+" "+(ptr->last_name))<<"*\n";
    cout<<"*Record Locator: "<<setw(37)<<(ptr->record)<<"*\n";
    
    if(ptr->return_type() == 1)
    cout<<"*Seat: First/"<<setw(41)<<ptr->return_seat_num()<<"*"<<endl;
    else 
    cout<<"Seat: Economy/"<<setw(40)<<ptr->return_seat_num()<<"*"<<endl;
    
    for(int i=0;i<55;i++)cout<<"*";

    
}

bool list::rd_exist(short rd)//use record number to search list if passenger in or not.
{
    passenger *ptr=first;
    for(int i=0;i<psg_num;i++,ptr=ptr->next)
    {
        if(ptr->record != rd)continue;
        return true;
    }
    return false;
}
