#include <iostream>
#include <string>
#include "airline.h"

using namespace std;

short selection;

int main()
{
    passenger psg1;

    main_menu();
    //selection = enter_type();

    switch(selection = enter_type())
    {
        case 1:
        new_reservation(psg1);
        break;


    }

    //cout<< selection <<endl;

    return 0;
}