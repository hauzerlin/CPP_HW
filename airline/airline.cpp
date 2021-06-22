#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <conio.h>
#include "check.h"
//#include "passenger.h"

using namespace std;

inline void err_reservation()
{
    cerr<<"No available seats and your reservation is not successfully made\n";
    cout<<"\n\n";
    getch();
    return;
}

//show the main menu and options.
void main_menu()
{
    //system("cls");

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
            for(int i=0;i<49;i++)cout<<"=";
            cout<<endl;
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
    //cache variable.
    passenger *psg = new passenger;
    string temp;
    char tmp2[10];
    int dob;
    long tmp;
    short type;

    srand(time(0));

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
    while(cin >> dob)
    {
        ltoa(tmp, tmp2, 10);
        string save(tmp2);
        if(save.length()!=8)
        {
            cerr<<"Wrong format! \nPlease enter passenger's DOB again: ";
            continue;
        }
        else  break;
    }
    psg->set_DOB(dob);

    //enter passport number.
    cout<<"Please enter passenger's passport number: ";
    //cin >> tmp;
    while(cin >> tmp)
    {
        ltoa(tmp, tmp2, 10);
        string save(tmp2);
        if(save.length()!=9)
        {
            cerr<<"Wrong format! \nPlease enter passenger's passport number again: ";
            continue;
        }
        else  break;
    }
    psg->set_passport_num(tmp);

    //select type of seat
    cout<<"Please type 1 for First Class\n";
    cout<<"Please type 2 for Economy Class: ";
    cin>>type;
    psg->set_type(type);


    if(type == 1)//if first class is secelted.
    {
        //check if first class seats is available, assign seat for this passenger.
        if(!first_full(seats))assign_first(psg, seats);
        else if(!economy_full(seats))//if economy class is still available, ask to chage to economy class seat.
        {
            //if "yes" is taken, assign a economy class seat.
            if(ask_change(2)==1)assign_economy(psg, seats);
            else {err_reservation();return;}
        }
        else {err_reservation();return;} //if first class and economy class all full. Print error message.
    }
    else if(type == 2)//if economy class is secelted.
    {
        if(!economy_full(seats))assign_economy(psg, seats);//check if economy class is available, assign a seat for this passenger.
        else if(!first_full(seats)) //if fist class is available, ask to change to fist class seat.
        {
            //if "yes" is taken, assign a first class seat.
            if(ask_change(1)==1)assign_first(psg, seats);
            else {err_reservation();return;}
        }
        else {err_reservation();return;}
        /*{
            cerr<<"No available seats and your reservation is not successfully made\n";
            cout<<"\n\n";
            getch();
            return;
        }*/
    }

    //Set up passenger's record locator.
    if(!record_full(record))assign_record(psg, record);    
    else return;
    
    //prsent list
    ls.Push(psg);

    cout<< "*** The reservation is successfully made! ***\n";
    psg->display_data();
    cout<<"\n\n";

    getch();

}

//when select type 4 at main menu, print record on screen.
void print_record(list& ls)
{   
    short rd;
    cout<<"Please enter record locator: ";
    cin>>rd;
    while(!ls.rd_exist(rd))
    {
        cout<<"The record locator you entered is wrong!\n";
        cout<<"Please enter your record locator again: ";
        cin>>rd;
    }
    ls.boarding_pass(rd);
    cout<<"\n\n";

}

//when select type 6 at main menu, exit the system.
void exit_system()
{
    cout<<"Thank you for using our system\n";
    cout<<"Have a nice trip~~";
}

void read_from_file(list &ls)
{
    ifstream psg_in;
    string filename;

    //open the file
    cout<<"Please enter the file name: ";
    cin>>filename;
    psg_in.open(filename, ios::binary | ios::in);
    if(!psg_in.is_open())// && filename.substr(0,1) != '6'
    {
        cerr<<"The file "<< filename <<"does not exist.\n";
        cout<<"\n\n";
        return;
        //cerr<<"Error! Can't open the file "<< filename <<" !\n";
        //cerr<<"Please enter again: ";//enter 6 to exit 
        //cin>>filename;
    }

    psg_in.seekg(65, ios::beg);
    /*
    string tmp;
    psg_in>>tmp;
    cout<<"test: "<<tmp<<endl;
    
    psg_in>>tmp;
    cout<<"test: "<<tmp<<endl;
    
    psg_in>>tmp;
    cout<<"test: "<<tmp<<endl;
    
    psg_in>>tmp;
    cout<<"test: "<<tmp<<endl;
    
    psg_in>>tmp;
    cout<<"test: "<<tmp<<endl;

    psg_in>>tmp;
    cout<<"test: "<<tmp<<endl;

    psg_in>>tmp;
    cout<<"test: "<<tmp<<endl;

    cout<<static_cast<int>('\r');*/

    //cout<< "next char: " << psg_in.peek() <<endl;
    
    while(psg_in.peek()!=EOF)
    {
        passenger *in = new passenger;
        ls.Push(in);

        int dob;
        string tmp;
        char name[20];
        long ps_num;
        short type, seat_num, rd;

        psg_in>>rd;
        //cout<<rd<<endl;
        in->set_record(rd);

        psg_in>>tmp;
        //cout<<tmp<<endl;
        in->set_first(tmp);

        psg_in>>tmp;
        //cout<<tmp<<endl;
        in->set_last(tmp);

        psg_in>>dob;
        //cout<<dob<<endl;
        in->set_DOB(dob);

        psg_in>>ps_num;
        //cout<<ps_num<<endl;
        in->set_passport_num(ps_num);

        psg_in>>tmp;
        //cout<<tmp<<endl;
        if(tmp[0]=='F')in->set_type(1);
        else in->set_type(2);

        psg_in>>seat_num;
        //cout<<seat_num<<endl;
        in->set_seat(seat_num);

        //psg_in.seekg(3, ios::cur);

    }    

    cout<<"The booking record is successfully saved to the file";
    cout<<"\n\n";

}
