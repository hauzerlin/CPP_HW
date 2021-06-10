/*Swapping node.cpp*/
//This code is going to swapping
//two ptr address

#include <iostream>
#include<stdio.h>

using namespace std;

struct node
{
    int data;
    node *next;
    node *preverous;
}linknode;

struct Queue
{
    node *front;//最前一個ptr
    node *rear;//尾巴的ptr
    int size;
};

void Push(Queue &q, int v)
{
    node *n = new node;
    n->data = v;
    n->next = NULL;
    if(q.front == NULL)    //queue是空的
    {
        q.front = q.rear = n;
    }
    else
    {
        n->preverous = q.rear;
        q.rear->next = n;    //先將尾巴接上去
        q.rear = n;        //再將queue的尾巴移到正確位置
    }
    q.size++;
}

void Display(Queue &q)
{
    for(node *n = q.front; n != NULL; n = n->next)
        {
            cout << n->data;
            if(n->next!=NULL) cout<< " " ;
        }
}

void ptr_switch(Queue &q, int sw1, int sw2)
{
    if(sw1==sw2)return;
    node *n = q.front;
    node *n1= NULL, *n2=NULL;
    int num;

    if(sw1>sw2){num=sw1; sw1=sw2; sw2=num;} //為方便計算設定(sw1<sw2)
    
    //記錄在sw1與sw2的ptr之next,preverous還有本身的地址
    for(num=1;num<=sw2;num++,n = n->next)
    {
        if(n->data == sw1)n1=n;
        else if(n->data == sw2)n2= n;

        if(n1!=NULL && n2!=NULL)break;
    }

    //cout<< "n1: " << n1 <<" n2: "<< n2 <<endl;

    if(n1==NULL||n2==NULL)return;

    //確認n1不是排頭
    if(n1!=q.front)
    {
        n=n1->preverous;
        n->next = n2;
    }
    else  q.front = n2;

    if(n2!=q.front)
    {
        n=n2->preverous;
        n->next =n1;
    }
    else q.front = n1;


    node *tmp = n2->next;
    n2->next = n1->next;
    n1->next = tmp;
}

int main(){
    Queue q;
    q.front = q.rear = NULL;    //一開始沒有資料，都先設為NULL指標。
    q.size = 0;

    int temp,sw1,sw2;

    //getchar()讀取下一個字元
    while(cin>>temp)
    {
        Push(q,temp);
        char t = getchar();
        if(t=='\n')break;
    }

    cin>>sw1>>sw2;
    ptr_switch(q, sw1, sw2);

    //印出完整的Linked list
    Display(q);

    return 0;
}
