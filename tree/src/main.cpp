// Creating slicing tree
// M1, M2, M3 function
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "tree_func.h"
#include "file_op.h"

using namespace std;

typedef enum operater{HORIZON, VERTICAL} OP;

//prototypes
void Check_Command_Format(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    Check_Command_Format(argc, argv);

    TreeNodePtr rootPtr=NULL; // tree initially empty

    // insert random values between 0 and 14 in the tree
   for (int i = 1; i <= 10; ++i) {
      int item = rand() % 15;
	  cout<<setw(3)<<item;
      insertNode(&rootPtr, item);
   }
   
   cout<<"\n";

    Read_file(&rootPtr,argv[1]);

    /*treeNode test;
    root=&test;
    test.operand = 12;
    test.operater = 'H';

    cout<<"test operand: "<< test.operand <<endl;
    cout<<"tets operater: "<< test.operater <<endl;

    cout<<endl;

    cout<<"root operand: "<< root->operand <<endl;
    cout<<"root operater: "<< root->operater <<endl;

    //InsertNode(&root,2);
    //test_func();*/
    return 0; 
}

void Check_Command_Format(int argc, char *argv[])
{
    if(argc!=3)
    {
        cerr<<"Wrong Command format!\n";
        exit(-1);
    }
    else cout<<"check command correct!!!\n";
}
