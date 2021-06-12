#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    int test;
    ifstream ifp1;
    string filename=argv[1];
    
    //If the command isn't fit the format,return a error message.
    //Tell user about the command format and usage.
    if(argc!=2)
    {
        cout<<"\nUsage... \n";
        cout<<".\\program file_name\n";
        cout<<"Ex.\n";
        cout<<".\\parser file_name\n\n";
        exit(0);
    }

    //Open the file "ifp1" and set the open moduel "ios::in".
    ifp1.open(filename, ios::in);

    //Testing the file is opening successfully or not.
    if(!ifp1.is_open())
    {
        cout<<"Erro!! Can't open pattern file: "<<filename<<" !!!\n";
        exit(0);
    }

    //Put the data of ifp1 on screen.
    while(ifp1>>test)
    {
        cout<< test;
        if(ifp1.get()!=EOF)cout<<" ";
    }

    //Everthing is done. Close the file ifp1.
    ifp1.close();

    return 0;
}