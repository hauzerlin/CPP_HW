//thie program is going to parser .lis file to .csv file

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void read_lis_file(char*);
void test_save_data();
void save_csv_file(char*);

vector <double> voltage,curren;
vector <string> operate;

string lis_filename;

int main(int argc,char **argv)
{
	read_lis_file(argv[argc-2]);
	test_save_data();
	save_csv_file(argv[argc-1]);
	
	return 0;
}

void read_lis_file(char* filename)
{
	ifstream lis_file;
	string operate1;
	int line=0;
	lis_file.open(filename, ios::binary | ios::in);

	if(!lis_file.is_open())
	{
		cerr<<"Error!! Can't open pattern file: ";
		cerr<<filename;
		cerr<<" !!!"<<endl;
		return;
	}
	else
	cout<<"file open successfully!!!"<<endl;

	while(!lis_file.eof())
	{
		/*lis_file>>operate1;
		if(lis_file.get()!='\n')
		{
			cout<<operate1<<" ";
		}
		else
		{
			cout<<operate1<<"\n";
		}*/
		getline(lis_file, operate1);
		if(operate1 == "x" || line>0)
		{
			line++;
			if(operate1 == "y")
			{
				line=0;
				break;
			}
			if(line > 4)
			{
				operate.push_back(operate1);
			}

		}
	}
}

void test_save_data()
{
	for(int i= 0; i<operate.size(); i++)
	cout<<operate[i]<<endl;
}

void save_csv_file(char* filename)
{
	ofstream csv_file;
	csv_file.open(filename, ios::binary | ios::out);

	if(!csv_file.is_open())
	{
		cerr<<"Error!! Can't open pattern file: ";
		cerr<<filename;
		cerr<<" !!!"<<endl;
		return;
	}
	else
	cout<<"file open successfully!!!"<<endl;

	for(int i=0; i<operate.size(); i++)
	{
		csv_file<<operate[i]<<endl;
	}
}