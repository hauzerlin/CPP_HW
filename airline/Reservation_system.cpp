#include <iostream>
#include <string>
#include "airline.h"

using namespace std;

short selection=0;
bool seats[10];
bool record[10];
list List;

int main()
{
    List.init();
    seats[10] = {0};
    record[10] = {0};
    passenger psg1;

    //main_menu();
    //selection = enter_type();
    while(selection!=6)
    {
        switch( main_menu(),selection = enter_type())
        {
            case 1:
            new_reservation(List, seats, record);
            break;

            case 3:
            List.Display_list();
            break;


            case 6:
            exit_system();
            break;


        }
    }
    //cout<< selection <<endl;

    return 0;
}