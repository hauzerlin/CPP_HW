#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "passenger.h"
using namespace std;

//show the main menu and options.
void main_menu()
{
    system("cls");

    cout<<"*** Welcome to NCU airline reservation system ***\n";
    for(int i=0;i<49;i++)cout<<"=";
    cout<<endl;
    cout<<"Please type 1 to make a new reservation\n";
    cout<<"Please type 2 to cancel an existing reservation\n";
    cout<<"Please type 3 to show current booking status\n";
    cout<<"Please type 4 to print boarding pass for a record\n";
    cout<<"Please type 5 to save all records in a file\n";
    cout<<"Please type 6 to exit the system\n";
    cout<<"Please type 7 to load data from a file\n";
}

//enter the type number on main menu.
short enter_type()
{
    short type;

    cout<<"Enter your selection Here: ";

    while(cin>>type)
    {
        if(type<=7&&type>=1)
        {
            for(int i=0;i<49;i++)cout<<"=";cout<<endl;
            break;
        }
        else
        {
            cout<< "Error type! Please enter your type agian.\n";
        }
    }
    return type;
}

//when select type 1 at main menu, push a new reservation.
void new_reservation(list &ls, bool seats[], bool record[])
{
    passenger *psg = new passenger;
    ls.Push(psg);
    string temp;
    long tmp;
    short type, tmp2;

    //enter first name.
    cout<<"Please enter passenger's first name: ";
    cin >> temp;
    psg->set_first(temp);
    
    //enter last name.
    cout<<"Please enter passenger's last name: ";
    cin >> temp;
    psg->set_last(temp);

    //enter "day of birth"
    cout<<"Please enter passenger's DOB: ";
    cin >> tmp;
    psg->set_DOB(tmp);

    //enter passport number.
    cout<<"Please enter passenger's passport number: ";
    cin >> tmp;
    psg->set_passport_num(tmp);

    //select type of seat
    cout<<"Please type 1 for First Class\n";
    cout<<"Please type 2 for Economy Class: ";
    cin>>type;
    psg->set_type(type);

    srand(time(0));

    if(type == 1)
    {
        while(tmp2 = (rand()%4)+1)
        {
            if(!seats[tmp2])break;
            else continue;
        }
        psg->set_seat(tmp2);

    }
    else
    {
         while(tmp2 = (rand()%6)+5)
        {
            if(!seats[tmp2])break;
            else continue;
        }
        psg->set_seat(tmp2);
    }

    while(tmp2 = (rand()%10)+1)
    {
            if(!record[tmp2])break;
            else continue;
    }
    psg->set_record(tmp2);
    //prsent list

    cout<< "*** The reservation is successfully made! ***\n";
    psg->display_data();
    //cout<<"\n\n";

    getch();

}

void exit_system()
{
    cout<<"Thank you for using our system\n";
    cout<<"Have a nice trip~~";
}