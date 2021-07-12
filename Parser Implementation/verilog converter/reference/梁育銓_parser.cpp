#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int calculate_index(int,int,int,int);

int main()
{
	
	string a,c,d,e;
	string filename;
	string outputfilename;
	string filename_extension=".v";
	int b[3]={};
	//b[0]=input's number;
	//b[1]=output's number;
	//b[2]=gate's number
	int wirenumber=0;


	//
	ifstream input;
	
	cout << "Please enter the input file name: ";
	cin >> filename;
	
	input.open(filename.c_str());
	//


	//
	int x=filename.length();// x means the file's length.
	outputfilename=filename.substr(0,x-6)+filename_extension;
	ofstream output;
	output.open(outputfilename.c_str());
	
	if(!input){
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	else{
		cerr << "The file "<< filename <<" is opened successfully." << endl;	
		cerr << "Converting " << outputfilename <<" files..." << endl;
		cerr << "Writing output files..." << endl;
	}
	//
	

	//to access the inputs, outputs and wires number.
	if(input >> a >> a)
		output << "module" << " " <<  a << " " << "(";
		
	for(int i=0;i<3;i++){
		if(input >> a >> b[i] >>a);
			/*cout << b[i] << endl;*/
	}
	//

	//assume that the number of input and output >999
	int inputindex_0digit[b[0]]={};
	int inputindex_1digit[b[0]]={};
	int inputindex_2digit[b[0]]={};
	int inputindex_3digit[b[0]]={};
	
	int outputindex_0digit[b[1]]={};
	int outputindex_1digit[b[1]]={};
	int outputindex_2digit[b[1]]={};
	int outputindex_3digit[b[1]]={};
	
	int inputindex[b[0]]={};
	int outputindex[b[1]]={};
	
	for(int i=0;i<b[0];i++){
		if(input >> a){
			if(a.length()==8){
				inputindex_0digit[i]=static_cast<int>(a[6]);
				inputindex_0digit[i]=inputindex_0digit[i]-48;
				inputindex[i]=calculate_index(0,0,0,inputindex_0digit[i]);
			}
			if(a.length()==9){
				inputindex_0digit[i]=static_cast<int>(a[7]);
				inputindex_0digit[i]=inputindex_0digit[i]-48;
				inputindex_1digit[i]=static_cast<int>(a[6]);
				inputindex_1digit[i]=inputindex_1digit[i]-48;
				inputindex[i]=calculate_index(0,0,inputindex_1digit[i],inputindex_0digit[i]);
			}
			if(a.length()==10){
				inputindex_2digit[i]=static_cast<int>(a[6]);
				inputindex_2digit[i]=inputindex_2digit[i]-48;
				inputindex_1digit[i]=static_cast<int>(a[7]);
				inputindex_1digit[i]=inputindex_1digit[i]-48;
				inputindex_0digit[i]=static_cast<int>(a[8]);
				inputindex_0digit[i]=inputindex_0digit[i]-48;
				inputindex[i]=calculate_index(0,inputindex_2digit[i],inputindex_1digit[i],inputindex_0digit[i]);
			}
			if(a.length()==11){
				inputindex_3digit[i]=static_cast<int>(a[6]);
				inputindex_3digit[i]=inputindex_3digit[i]-48;
				inputindex_2digit[i]=static_cast<int>(a[7]);
				inputindex_2digit[i]=inputindex_2digit[i]-48;
				inputindex_1digit[i]=static_cast<int>(a[8]);
				inputindex_1digit[i]=inputindex_1digit[i]-48;
				inputindex_0digit[i]=static_cast<int>(a[9]);
				inputindex_0digit[i]=inputindex_0digit[i]-48;
				inputindex[i]=calculate_index(inputindex_3digit[i],inputindex_2digit[i],inputindex_1digit[i],inputindex_0digit[i]);
			}
		}
		/*cout << inputindex[i] << endl;*/
	}	//??input??index?????X??(??e?u??w?????) 
	
	for(int i=0;i<b[1];i++){
		if(input >> a){
			if(a.length()==9){
				outputindex_0digit[i]=static_cast<int>(a[7]);
				outputindex_0digit[i]=outputindex_0digit[i]-48;
				outputindex[i]=calculate_index(0,0,0,outputindex_0digit[i]);
			}
			if(a.length()==10){
				outputindex_0digit[i]=static_cast<int>(a[8]);
				outputindex_0digit[i]=outputindex_0digit[i]-48;
				outputindex_1digit[i]=static_cast<int>(a[7]);
				outputindex_1digit[i]=outputindex_1digit[i]-48;
				outputindex[i]=calculate_index(0,0,outputindex_1digit[i],outputindex_0digit[i]);
			}
			if(a.length()==11){
				outputindex_2digit[i]=static_cast<int>(a[7]);
				outputindex_2digit[i]=outputindex_2digit[i]-48;
				outputindex_1digit[i]=static_cast<int>(a[8]);
				outputindex_1digit[i]=outputindex_1digit[i]-48;
				outputindex_0digit[i]=static_cast<int>(a[9]);
				outputindex_0digit[i]=outputindex_0digit[i]-48;
				outputindex[i]=calculate_index(0,outputindex_2digit[i],outputindex_1digit[i],outputindex_0digit[i]);
			}
			if(a.length()==12){
				outputindex_3digit[i]=static_cast<int>(a[7]);
				outputindex_3digit[i]=outputindex_3digit[i]-48;
				outputindex_2digit[i]=static_cast<int>(a[8]);
				outputindex_2digit[i]=outputindex_2digit[i]-48;
				outputindex_1digit[i]=static_cast<int>(a[9]);
				outputindex_1digit[i]=outputindex_1digit[i]-48;
				outputindex_0digit[i]=static_cast<int>(a[10]);
				outputindex_0digit[i]=outputindex_0digit[i]-48;
				outputindex[i]=calculate_index(outputindex_3digit[i],outputindex_2digit[i],outputindex_1digit[i],outputindex_0digit[i]);
			}
		/*cout << outputindex[i] << endl;*/
		}	//??input??index?????X?? (??e?u??w?????)
	} 
	
	for(int i=0;i<b[0];i++){
		 output << "N" << inputindex[i] << ",";
	}
	
	for(int i=0;i<(b[1]-1);i++){
		output << "N" << outputindex[i] << ",";
	}
	
	output << "N" << outputindex[b[1]-1] << ");" << endl << endl;//?L??module 
	output << "input ";
	
	for(int i=0;i<(b[0]-1);i++){
		output << "N" << inputindex[i] << ",";
	}
	output << "N" << inputindex[b[0]-1] << ";" << endl << endl;//?L??input 
	
	output << "output ";
	for(int i=0;i<(b[1]-1);i++){
		output << "N" << outputindex[i] << ",";
	}
	output << "N" << outputindex[b[1]-1] << ";" << endl << endl;//?L??output
	
	//int wireindex[]={};
	int nandparameter[b[2]][3]={};
	
	output << "wire ";
	for(int i=0;i<b[2];i++){
		int temp=0,count=0;
		if(input >> temp >> c >> d >> e){
			for(int j=0;j<b[1];j++){
				if(temp!=outputindex[j])
					count++;
			}
			if(count==b[1])
				output << "N" << temp << ",";
			
			nandparameter[i][0]=temp;
			
			if(d.length()==7){
				d[5]=d[5]-48;
				nandparameter[i][1]=calculate_index(0,0,0,static_cast<int>(d[5]));
			}
			if(d.length()==8){
				d[5]=d[5]-48;
				d[6]=d[6]-48;
				nandparameter[i][1]=calculate_index(0,0,static_cast<int>(d[5]),static_cast<int>(d[6]));
			}
			if(d.length()==9){
				d[5]=d[5]-48;
				d[6]=d[6]-48;
				d[7]=d[7]-48;
				nandparameter[i][1]=calculate_index(0,static_cast<int>(d[5]),static_cast<int>(d[6]),static_cast<int>(d[7]));
			}
			if(d.length()==10){
				d[5]=d[5]-48;
				d[6]=d[6]-48;
				d[7]=d[7]-48;
				d[8]=d[8]-48;
				nandparameter[i][1]=calculate_index(static_cast<int>(d[5]),static_cast<int>(d[6]),static_cast<int>(d[7]),static_cast<int>(d[8]));
			}
			
			if(e.length()==2){
				e[0]=e[0]-48;
				nandparameter[i][2]=calculate_index(0,0,0,static_cast<int>(e[0]));
			}
			if(e.length()==3){
				e[0]=e[0]-48;
				e[1]=e[1]-48;
				nandparameter[i][2]=calculate_index(0,0,static_cast<int>(e[0]),static_cast<int>(e[1]));	
			}
			if(e.length()==4){
				e[0]=e[0]-48;
				e[1]=e[1]-48;
				e[2]=e[2]-48;	
				nandparameter[i][2]=calculate_index(0,static_cast<int>(e[0]),static_cast<int>(e[1]),static_cast<int>(e[2]));	
			}
			if(e.length()==5){
				e[0]=e[0]-48;
				e[1]=e[1]-48;
				e[2]=e[2]-48;
				e[3]=e[3]-48;	
				nandparameter[i][2]=calculate_index(static_cast<int>(e[0]),static_cast<int>(e[1]),static_cast<int>(e[2]),static_cast<int>(e[3]));	
			}
		}
	}
	/*for(int i=0;i<b[2];i++){
		for(int j=0;j<3;j++){
			cout << nandparameter[i][j] << " " ;
		}
		cout << endl;
	}*/
	output.seekp(-1,ios::cur);
	output << ";" << endl << endl;
	
	for(int i=0;i<b[2];i++){
		output << "nand " << "NAND2_" << i+1 << " ("; 
		for(int j=0;j<3;j++){
			output << "N" << nandparameter[i][j] << ", "; 
		}
		output.seekp(-2,ios::cur);
		output << ");" << endl;
	}
	
	output << endl << "endmodule";
	//for(int i=0;i<wirenumber;i++)
	//	cout << wireindex[i] << endl;
	cout << "Converting successfully!";
}

//convert the string number to integer.
int calculate_index(int third_digit, int second_digit, int first_digit, int zeroth_digit)
{
	int index;
	index=1000*third_digit+100*second_digit+10*first_digit+1*zeroth_digit;
	return index;
}
