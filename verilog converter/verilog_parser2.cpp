#include <iostream>
#include <fstream>

using namespace std;

ifstream infile;
ofstream outfile;
string in_filename;
string out_filename;//Set up in Read_file function.

string operate;
int input[2000];
int output[2000];
int compoment;

void Read_file(void);//Cin a file name and open the file.
void convert_module(void);

int main()
{
    string temp;
 
    Read_file();


    /*infile.seekg(0, ios::beg);
    while(getline(infile,temp))
    {
        cout<<temp<<" "<<infile.tellg()<<"\n";
    }*/

    convert_module();

    /*infile.seekg(0);
    for(int i=0;i<5;i++)
    cout<<static_cast<char>(infile.get());*/

    infile.close();

    return 0;
}

//Read file name from cin and open it.
//If file isn't open then reply a error message.
void Read_file(void)
{
    //Input the file name and open it.
    cout<<"Please input file name: \n";
    cin>>in_filename;
    
    infile.open(in_filename,ios::binary |ios::in);
    
    infile.clear();

    //test the input file is open sucessfully or not.
    if(!infile.is_open())
    {
        cerr<<"Error! Can't openfile: "<< in_filename <<" !!!\n";
        exit(0);
    }
    else
    {
        //Print the file open successfully message.
        cout <<"The file "<< in_filename <<" is opened successfully.\n";
        cout <<"Converting "<< out_filename <<" files...\n";

        //cout <<"Writing files...\n";

        out_filename = in_filename.substr(0,in_filename.length()-6)+".v";
        outfile.open(out_filename, ios::out);
    }
}

void convert_module()
{
    infile.seekg(2,ios::beg);//Set position indicator at 2 chars form beginning.

    //cout<< infile.tellg() <<" "<<static_cast<char>(infile.peek()) <<endl;
    //infile>>operate;
    getline(infile, operate,'\n');
    //cout<< operate <<endl;
    outfile <<"module "<< operate <<" (";

    infile.seekg(2,ios::cur);
    infile>>input[0];
    //cout<<"input: "<< input[0] <<endl;

    infile.ignore(10,'\n');
    infile.seekg(2, ios::cur);
    infile>>output[0];
    //cout<<"output: "<< output[0] <<endl;

    infile.ignore(30,'\n');
    infile.seekg(2, ios::cur);
    infile>>compoment;
    //cout<<"NAND: "<<compoment<<endl;
}