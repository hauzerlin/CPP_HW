//Create captial.cpp
//using vector or pointer to input and output a sentense.
#include <iostream>
#include <stdlib.h>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout<<"Input Line: ";
    char *save = (char*)malloc( 100*sizeof(char) );
    cin.getline(save,100);

    if(*save>=97 && *save<=122)*save-=32;

    cout<<"Output Line: ";

    while(true)
    {
        if( (*save)==' '&& *(save+1)!=' ')
        {
            save++;
            *save-=32;
            cout<<" "<<*save;
        }
        else cout<<(*save);
        save++;
        if((*save)=='\0')break;
    }

    free(save);
    return 0;
}

