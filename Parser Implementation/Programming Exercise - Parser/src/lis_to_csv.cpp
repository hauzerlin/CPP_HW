//thie program is going to parser .lis file to .csv file

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void Save_csv_file(char*);
void Read_lis_file(char*);
void Test_save_data();
double Separate_data(string number, int VorI);
void Convert_data();


vector <double> voltage,curren;
vector <string> operate;

string lis_filename;

int main(int argc,char **argv)
{
	Read_lis_file(argv[argc-2]);
	Convert_data();
	//Test_save_data();
	//cout<<setprecision(10)<<Separate_data("657.0551u")<<endl;
	Save_csv_file(argv[argc-1]);
	
	return 0;
}

void Read_lis_file(char* filename)
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

void Test_save_data()
{
	for(int i= 0; i<operate.size(); i++)
	{
		cout<<setprecision(10)<<voltage[i]<<" ";
		cout<<setprecision(10)<<curren[i]<<"\n";
	}
}

void Save_csv_file(char* filename)
{
	ofstream csv_file;
	csv_file.open(filename, ios::binary | ios::out);
	double mean_volt=0, mean_curren=0;

	if(!csv_file.is_open())
	{
		cerr<<"Error!! Can't open pattern file: ";
		cerr<<filename;
		cerr<<" !!!"<<endl;
		return;
	}
	else
	cout<<"file open successfully!!!"<<endl;

	csv_file<<"volt,current"<<endl;

	for(int i=0; i<operate.size(); i++)
	{
		//mean_volt+=voltage[i];
		mean_curren+=curren[i];
		csv_file<<voltage[i]<<","<<curren[i]<<endl;
	}

	//mean_volt/=(double)operate.size();
	mean_curren/=(double)operate.size();

	csv_file<<"Avg,"<<setprecision(10)<<mean_curren<<endl;
}

void Convert_data()
{
	string temp;

	for(int i=0; i<(int)operate.size(); i++)
	{
		//cout<<operate[i].size()<<endl;

		temp = operate[i].substr(2,10);
		voltage.push_back(Separate_data(temp,1));
		//cout<<voltage.back()<<"\t";
		//cout<<temp<<"\t";

		temp = operate[i].substr(13,12);
		curren.push_back(Separate_data(temp,0));
		//cout<<Separate_data(temp,0)<<"\n";
		//cout<<temp<<endl;
	}	
}

//v=1;i=0;
double Separate_data(string number, int VorI)
{
	double fix=1;
	double temp;

	if(VorI && number.back() =='m')
	{
		fix = 0.001;
		temp = atoi(number.c_str());
		temp*=fix;
		return temp;
	}
	else if(number.back()=='u'){fix=0.001;}

	temp = stod(number);
	temp*=fix;
	

	return temp;	

}