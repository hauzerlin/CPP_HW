#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout<<"Input Line: ";

    char save[50];
    char *pt = save;
    cin.getline(save,50);

    if(*pt>=97 && *pt<=122)*pt-=32;

    cout<<"Output Line: ";

    while(true)
    {
        if( (*pt)==' '&& *(pt+1)!=' ')
        {
            pt++;
            *pt-=32;
            cout<<" "<<*pt;
        }
        else cout<<(*pt);
        pt++;
        if((*pt)=='\0')break;
    }

    return 0;
}
