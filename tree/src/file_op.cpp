#include <iostream>
#include <fstream>
#include <string>
#include "tree_func.h"
#include "file_op.h"

using namespace std;

ifstream infile;
ofstream outfile;

//回傳一個存放input file第一行的linked list 結構
queue_post Read_file(TreeNodePtr *root, char** filename)
{
    //cout<<"\nfilename: "<<filename<<endl;
    queue_post Queue;
    string op1, op2, op3;
    int Movetime;

    infile.open(filename[1], ios::binary|ios::in);
    if(!infile.is_open())
    {
        cerr<<"File: "<<filename<<" isn't open.";
        exit(-1);
    }

    char temp[100];
    infile.getline(temp, 100);
    string tmp(temp);
    //cout<<tmp<<endl;
    int blank=0;
    for(int i=0;temp[i]!='\r';i++)
    {
        if(temp[i]==' ')blank++;
    }

    //cout<<(char)infile.get()<<endl;
    //cout<<(char)infile.get()<<endl;
    //cout<<(char)infile.get()<<endl;

    //cout<<"size: "<<blank+1<<endl;
    Post_Links_Build(Queue, tmp, blank+1);
    Display(Queue);
    cout<<endl;

    //infile.ignore(20,'\n');
    infile.ignore(20,'\n');
    infile.ignore(20,'\n');

    infile.seekg(9,ios::cur);
    infile>>Movetime;
    cout<<"Movetime: "<<Movetime<<endl;

    infile.ignore(20,'\n');
    infile.ignore(20,'\n');
    
    Save_tree_toFile(root,filename[2]);
    //int case1=0, case2=0, case3=0;
    for(int i=0;i<Movetime;i++)
    {
        infile>>op1;
        switch(op1[1])
        {
            case '1':
            {
                //case1++;
                infile>>op2>>op3;
                cout<<"M"<<op1[1]<<" "<<op2<<" "<<op3<<endl;
                M1(Queue,op2,op3);
                Write_to_file(Queue, &outfile);
                Display(Queue);
                cout<<endl;
                infile.ignore(20,'\n');
                break;
            }  
            case '2':
            {
                //case2++;
                infile>>op2;
                //cout<<"op2: "<<op2<<endl;
                int num2 = atoi(op2.c_str());
                cout<<"M"<<op1[1]<<" "<<op2<<endl;
                M2(Queue,num2);
                Write_to_file(Queue, &outfile);
                Display(Queue);
                cout<<endl;
                infile.ignore(20,'\n');
                break;
            }
            default:
            {
                //case3++;
                infile>>op2>>op3;
                //cout<<"op2: "<<op2<<"  op3: "<<op3<<endl;
                cout<<"M"<<op1[1]<<" "<<op2<<" "<<op3<<endl;
                M3(Queue, op2, op3);
                Write_to_file(Queue, &outfile);
                Display(Queue);
                cout<<endl;
                infile.ignore(20,'\n');
                break;
            }
        }
        //cout<<"case 1, 2, 3: "<< case1 <<" "<<case2<<" "<<case3<<endl;
    }
    //infile.seekg(1,ios::cur);

    //cout<<"infile test: "<<(char)infile.get()<<endl;
    //for(int i=0; i<8;i++)
    //cout<<(char)infile.get();
    //cout<<endl;
    //cout<<"infile test:"<<(char)infile.get()<<endl;


    /*infile.seekg(0);
    for(int i=0;i<blank+1;i++)
    {
        infile>>tmp;
        cout<<tmp<<" ";
    }*/

    
    return Queue;
}

void Save_tree_toFile(TreeNodePtr *root, char *filename)
{
    outfile.open(filename, ios::binary|ios::out);
    if(!outfile.is_open())
    {
        cerr<<"File: "<<filename<<" isn't open.";
        exit(-1);
    }
}

//建立一個Queue並將資料push到link node的結構中
void Post_Links_Build(queue_post &Queue, string first_line, int size)
{
    string temp;
    Queue.first = Queue.rear = NULL;
    Queue.num = 0;

    int line_len;
    line_len = first_line.length();

    infile.seekg(0);
    for(int i=0;i<size;i++)
    {
        infile>>temp;
        Push(Queue,temp);
    }
}

//將資料push到link node中
void Push(queue_post &Queue, string temp)
{
    linknode *n = new linknode;
    n->item = temp;
    n->next = NULL;
    n->prev = NULL;

    if(Queue.first == NULL)
    {
        Queue.first = Queue.rear = n;
    }
    else 
    {
        n->prev = Queue.rear;
        Queue.rear->next = n;
        Queue.rear = n;
    }
    Queue.num++;
}

//Display 一個Queue的完整node
void Display(queue_post & Queue)
{
    for(linknode *n = Queue.first; n != NULL; n = n->next)
        {
            cout << n->item;
            if(n->next!=NULL) cout<< " " ;
        }
}

void Write_to_file(queue_post &Queue, ofstream *out)
{
    for(linknode *n = Queue.first; n != NULL; n = n->next)
        {
            *out << n->item;
            if(n->next!=NULL) *out<< " " ;
        }
    *out<<"\n";
}