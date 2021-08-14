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
    TreeNodePtr *temp;

    //save first line of input file in linked list.
    //and read the file.
    Queue = Read_file(&rootPtr,argv);
    
    restruct_tree(&rootPtr,Queue);
    restruct_tree(&rootPtr,Queue);

    cout<<"tree postorder: \n";
    postOrder(rootPtr);
    cout<<endl;

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
