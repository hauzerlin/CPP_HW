//Read file from command line.

#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

fstream ifp1;//File for input.
fstream ofp1;//File for output.
string ip_filename;//input file's name.
string op_filename;//output file's name.

//Read file name form command line and open it.
void Read_file(int argc, char **argv);

int main(int argc, char **argv)
{
    string test;

    Read_file(argc, argv);

    cout<<"\n"<<op_filename<<endl;

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

//fetch the file name from command line.
//Open the file, if not sending a error message.
void Read_file(int argc, char **argv)
{
    ip_filename=argv[1];
    
    //If the command isn't fit the format,return a error message.
    //Telling user about the command format and usage.
    if(argc!=2)
    {
        cout<<"\nUsage... \n";
        cout<<".\\program file_name\n\n";
        exit(0);
    }

    //Open the file "ifp1" and set the open moduel "ios::in".
    ifp1.open(ip_filename, ios::in);

    //Testing the file is opening successfully or not.
    if(!ifp1.is_open())
    {
        cout<<"Error!! Can't open pattern file: "<<ip_filename<<" !!!\n";
        exit(0);
    }
    else 
    {
        op_filename = ip_filename.substr(0,(ip_filename.length())-6)+".v";
    }

}