#include <iostream>
#include <fstream>

using namespace std;

fstream infile;

void Read_file(void);//Cin a file name and open the file.

int main()
{
    string temp;
 
    Read_file();

    while(infile>>temp)
    {
        cout<<temp;
        if(infile.get()!=EOF)cout<<" ";
    }

    infile.close();

    return 0;
}

//Read file name from cin and open it.
//If file isn't open then reply a error message.
void Read_file(void)
{
    string filename;

    cout<<"Please input file name: \n";
    cin>>filename;
    
    infile.open(filename, ios::in);

    if(!infile.is_open())
    {
        cout<<"Error! Can't openfile: "<< filename <<" !!!\n";
        exit(0);
    }
}