#include <iostream>
#include "passenger.h"
using namespace std;

//show the main menu.
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

//enter the type number.
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

void new_reservation(passenger &psg)
{
    string temp;
    long tmp;
    short type;

    cout<<"Please enter passenger's first name: ";
    cin >> temp;
    psg.set_first(temp);
    
    cout<<"Please enter passenger's last name: ";
    cin >> temp;
    psg.set_last(temp);

    cout<<"Please enter passenger's DOB: ";
    cin >> tmp;
    psg.set_DOB(tmp);

    cout<<"Please enter passenger's passport number: ";
    cin >> tmp;
    psg.set_passport_num(tmp);

    cout<<"Please type 1 for First Class\n";
    cout<<"Please type 2 for Economy Class: ";
    cin>>type;
    psg.set_type(type);
    
    //cout<< "\n";
    //psg.display_name();
    //psg.display_data();

}

