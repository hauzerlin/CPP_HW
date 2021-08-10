#include <iostream>
#include <fstream>
#include "tree_func.h"

using namespace std;

ifstream infile;
ofstream outfile;

void Read_file(TreeNodePtr *root, char* filename)
{
    //cout<<"\nfilename: "<<filename<<endl;
    
    infile.open(filename, ios::binary|ios::in);
    if(!infile.is_open())
    {
        cerr<<"File: "<<filename<<" isn't open.";
        exit(-1);
    }

    while(!infile.eof())
    {
        char temp[100];
        infile.getline(temp, 100);
        cout<<temp<<endl;
    }

    /*// traverse the tree inOrder
    cout<<"\n\nThe inOrder traversal is:";
    inOrder(*root);
    cout<<"\ntest file function."<<endl;*/
}