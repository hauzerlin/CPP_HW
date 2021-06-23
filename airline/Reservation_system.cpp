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

    system("cls");

    while(selection!=6)
    {
        switch( main_menu(),selection = enter_type())
        {
            case 1:
            new_reservation(List, seats, record);
            break;

            case 2:
            cancel_reservation(List, seats, record);
            break;

            case 3:
            show_book_status(List, seats, record);
            break;

            case 4:
            print_record(List);
            break;

            case 5:
            break;

            case 6:
            exit_system();
            break;

            case 7:
            read_from_file(List, seats, record);
            break;

            case 8:
            check_list(seats, record);
            break;

            case 9:
            List.Display_list();
            break;

        }
    }
    return 0;
}