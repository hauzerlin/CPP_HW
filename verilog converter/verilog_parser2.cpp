#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filename;
    string temp;
    fstream infile;

    cout<<"Please input file name: \n";
    cin>>filename;
    
    infile.open(filename, ios::in);

    if(!infile.is_open())
    {
        cout<<"Error! Can't openfile: "<< filename <<" !!!\n";
        exit(0);
    }

    while(infile>>temp)
    {
        cout<<temp;
        if(infile.get()!=EOF)cout<<" ";
    }

    infile.close();

    return 0;
}