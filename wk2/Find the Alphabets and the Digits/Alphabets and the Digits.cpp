//Find the Alphabets and the Digits
//alphabets: A~Z: 65-90 a~z: 97-122
//digits: 48-57
//Special characters:none of above.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main ()
{
    cout<<"Please input a string:"<<endl;

    int alphabet=0, digit=0, sp_char=0;

    char save[1000];
    char *pt = save;
    cin.getline(save,1000);

    while(*pt!='\0')
    {
        if(*pt>=65 && *pt<=90)alphabet++;
        else if(*pt>=97 && *pt<=122)alphabet++;
        else if(*pt>=48 && *pt<=57)digit++;
        else sp_char++;
        pt++;
    }

    cout<< "Number of Alphabets in the string is: " << alphabet << endl;
    cout<< "Number of Digits in the string is: " << digit <<endl;
    cout<< "Number of Special characters in the string is: " << sp_char;

    return 0;
}
