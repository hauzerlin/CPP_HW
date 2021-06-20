#include <iostream>
#include <string>
#include "airline.h"

using namespace std;

int main()
{
    //list ps_list;

    string first = "lin", last = "haotse";
    passenger test(first, last);

    test.display_name();

    test.set_name("hello","world");
    test.display_name();

    system("pause");
    system("cls");
    cout<<"test line"<<endl;
    cout<< main_menu() <<endl;

    return 0;
}