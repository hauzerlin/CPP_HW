#include <iostream>
#include <fstream>

using namespace std;

ifstream infile;
ofstream outfile;
string in_filename;
string out_filename;//Set up in Read_file function.

string operate;
short inputs[2000];
short outputs[2000];
short wires[500];
short wire1[500];
short wire2[500];

void OPEN_file(void);//Cin a file name and open the file.
void Read_input(void);
void Write_output(void);

int main()
{
    string temp;
 
    OPEN_file();

    Read_input();

    Write_output();

    infile.close();
    outfile.close();

    return 0;
}

//Read file name from cin and open it.
//If file isn't open then reply a error message.
void OPEN_file(void)
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
        outfile.open(out_filename, ios::binary | ios::out);
    }
}

void Read_input()
{
    int i=0, o=0, w=0;

    //cout<< infile.tellg() <<" "<<static_cast<char>(infile.peek()) <<endl;
    infile.seekg(2,ios::beg);//Set position indicator at 2 chars form beginning.

    infile>>operate;
    //getline(infile, operate,'\n');
    outfile <<"module "<< operate <<" (";

    //To know the number of "inputs".
    infile.seekg(3,ios::cur);
    infile>>inputs[0];
    //cout<<"input: "<< inputs[0] <<endl;
    infile.ignore(10,'\n');

    //To know the number of "outputs".
    infile.seekg(2, ios::cur);
    infile>>outputs[0];
    infile.ignore(10,'\n');

    //To know the number of "NAND"
    infile.seekg(2, ios::cur);
    infile>>wires[0];
    infile.ignore(10,'\n');
    
    infile.ignore(10,'\n');


    //Input area
    for(int m=0; m<inputs[0]; m++)
    {
        i++;
        infile.seekg(6, ios::cur);
        infile>>inputs[i];
        infile.ignore(10, '\n');
    }

    infile.ignore(10,'\n');

    //Output area
    for(int m=0; m<outputs[0]; m++)
    {
        o++;
        infile.seekg(7, ios::cur);
        infile>>outputs[o];
        infile.ignore(10, '\n');

    }

    //Wires area
    for(int k=0; k<wires[0]; k++)
    {
        w++;
        //infile.seekg(7, ios::cur);
        infile>>wires[w];
        infile.ignore(10, '(');
        infile>>wire1[w];
        infile.seekg(2, ios::cur);
        infile>>wire2[w];
        infile.ignore(10,'\n');

    }
}

void Write_output(void)
{
    //complete first line in output file.
    for(int i=1;i<=(inputs[0]+outputs[0]);i++)
    {
        if(i<=inputs[0])
        {
            outfile<<"N"<<inputs[i]<<",";
        }
        else
        {
            outfile<<"N"<<outputs[i-inputs[0]];
            if(i < (inputs[0]+outputs[0]))outfile<<",";
            else outfile<<");\n\n";
        }
    }

    //third line(input)
    outfile<<"input ";
    for(int i=1;i<=inputs[0];i++)
    {
        outfile<<"N"<<inputs[i];
        if(i<inputs[0])outfile<<",";
        else outfile<<";\n\n";
    }

    //fifth line(output)
    outfile<<"output ";
    for(int i=1;i<=outputs[0];i++)
    {
        outfile<<"N"<<outputs[i];
        if(i<outputs[0])outfile<<",";
        else outfile<<";\n\n";
    }

    //seventh line(wire)
    outfile<<"wire ";
    for(int i=1;i<=wires[0]-outputs[0];i++)
    {
        outfile<<"N"<<wires[i];
        if(i<wires[0]-outputs[0])outfile<<",";
        else outfile<<";\n\n";
    }

    //Body of output file.
    for(int i=1;i<=wires[0];i++)
    {
        outfile<<"nand NAND2_"<<i<<" (";
        outfile<<"N"<<wires[i]<<", ";
        outfile<<"N"<<wire1[i]<<", ";
        outfile<<"N"<<wire2[i]<<");\n";
    }

    outfile<<"\nendmodule\n";

    cout<<"Converting successfully!";
}
