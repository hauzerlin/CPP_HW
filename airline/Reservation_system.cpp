#include <iostream>
#include <string>
#include "passenger.h"
#include "screen.h"

using namespace std;

short selection;

int main()
{
    string first = "lin", last = "haotse";
    passenger test(first, last);

    test.display_name();

    test.set_name("hello","world");
    test.display_name();

    system("pause");
    system("cls");
    //cout<<"test line"<<endl;
    main_menu();
    selection = enter_type();

    cout<< selection <<endl;

    return 0;
}