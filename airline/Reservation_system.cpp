#include <iostream>
#include <string>
#include "airline.h"

using namespace std;

short selection;
bool seats[10];
bool record[10];

int main()
{
    seats[10] = {0};
    record[10] = {0};
    passenger psg1;

    main_menu();
    //selection = enter_type();

    switch(selection = enter_type())
    {
        case 1:
        new_reservation(psg1, seats, record);
        break;


    }

    //cout<< selection <<endl;

    return 0;
}