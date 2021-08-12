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
queue_post Queue;


//prototypes
void Check_Command_Format(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    Check_Command_Format(argc, argv);

    TreeNodePtr rootPtr=NULL; // tree initially empty

    //if(Num_or_OP('h'))cout<<"h is a OP"<<endl;
    //if(!Num_or_OP('0'))cout<<"0 is a number"<<endl;

    //save first line of input file in linked list.
    //and read the file.
    Queue = Read_file(&rootPtr,argv[1]);
    
    //Display(Queue);

    //cout<<"\nthe nodes number is: "<<Queue.num<<endl;

    /*cout<<"Queue's first: "<<Queue.first->item<<endl;
    cout<<"QUeue's rear:"<<Queue.rear->item<<endl;*/

    //Link_node_Switch(Queue,"1","V");
    /*M1(Queue, "4", "3");

    cout<<"M1 4 3"<<endl;
    Display(Queue);

    M2(Queue, 1);

    cout<<"\nM2 1"<<endl;
    Display(Queue);

    //cout<<"\nthe nodes number is: "<<Queue.num<<endl;

    M3(Queue,"4", "2");

    cout<<"\nM3 4 2"<<endl;
    Display(Queue);*/
    
    //cout<<"\nthe nodes number is: "<<Queue.num<<endl;
    /*string tmp1="1", tmp2= "1", tmp3 = "3";
    cout<<tmp1.compare(tmp2)<<endl;
    cout<<tmp2.compare(tmp3)<<endl;*/


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
