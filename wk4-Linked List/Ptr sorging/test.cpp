#include <iostream>
#include<stdio.h>

using namespace std;

//Each node of the linked list.
struct node
{
    int data;
    node *next;
    node *preverous;
}linknode;

//main struct to save the ptr of first pointer.
struct Queue
{
    node *front;//最前一個ptr
    node *rear;//尾巴的ptr
    int size;
};

void Push(Queue &q, int v);//Add elements to the queue.
void Display(Queue &q);//Display the whole linked list.
void B_Display(Queue &q);
void ptr_switch(Queue &q, int sw1, int sw2);//switch the "position" of ptr at sw1 and sw2.
void ptr_sort(Queue &q);//Sorting Queue form the smallest number to the large number. 


int main(){
    Queue q;
    q.front = q.rear = NULL;    //一開始沒有資料，都先設為NULL指標。
    q.size = 0;

    int temp,sw1,sw2;

    //以數字加空白的形式輸入所有資料
    //至最後一個數字輸入後按下Enter
    //所有資料一次讀取進Linked list
    //getchar()讀取下一個字元
    while(cin>>temp)
    {
        Push(q,temp);
        char t = getchar();
        if(t=='\n')break;
    }
    
    ptr_sort(q);
    
    //印出完整的Linked lists
    Display(q);
    
    return 0;
}


//Add elements to the queue.
void Push(Queue &q, int v)
{
    node *n = new node;
    n->data = v;
    n->next = NULL;
    n->preverous = NULL;
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

//Display the whole linked list.
void Display(Queue &q)
{
    for(node *n = q.front; n != NULL; n = n->next)
        {
            cout << n->data;
            if(n->next!=NULL) cout<< " " ;
        }
}

void B_Display(Queue &q)
{
    for(node *n = q.rear; n!=NULL; n = n->preverous)
        {
            cout<< n->data;
            if(n->preverous!=NULL)cout<<" ";
        }
}

//switch the "position" of ptr at sw1 and sw2.
void ptr_switch(Queue &q, int sw1, int sw2)
{
    if(sw1==sw2)return;
    if(sw1>q.size||sw2>q.size)return;

    node *n = q.front;
    node *n1= NULL, *n2= NULL;
    int num;

    if(sw1>sw2){num=sw1; sw1=sw2; sw2=num;} //為方便計算設定(sw1<sw2)
    
    //記錄在sw1與sw2的ptr之next,preverous還有本身的地址
    for(num=1;num<=sw2;num++,n = n->next)
    {
        if(num==sw1) n1=n;
        else if(num==sw2) n2=n;

        if(n1!=NULL && n2!=NULL)break;
    }

    if(n2==NULL||n1==NULL)return;

    //cout<<"n2: "<< n2->data <<"\nn1: "<< n1->data <<endl;
    if(n1->next==n2)
    {
        //確認n1不是排頭
        if(n1!=q.front)
        {
            n=n1->preverous;
            n->next = n2;
        }
        else  
        {
            q.front = n2;
        }
            n=n1;
            n->next =n2->next;

        if(n2!=q.rear)
        {
            n=n2->next;
            n->preverous = n1;
        }
        else
        {
            q.rear = n1;
        }
            n=n2;
            n->preverous = n1->preverous;

        n1->preverous = n2;
        n2->next = n1;
    }
    else
    {
        //確認n1不是排頭
        if(n1!=q.front)
        {
            n=n1->preverous;
            n->next = n2;
        }
        else  
        {
            q.front = n2;
        }
            n=n2->preverous;
            n->next =n1;

        if(n2!=q.rear)
        {
            n=n2->next;
            n->preverous = n1;
        }
        else
        {
            q.rear = n1;
        }
            n=n1->next;
            n->preverous = n2;

        node *tmp = n2->next;
        n2->next = n1->next;
        n1->next = tmp;

        tmp = n2->preverous;
        n2->preverous = n1->preverous;
        n1->preverous = tmp;
    }
}

void ptr_sort(Queue &q)
{
    node *n = q.front;//operation ptr
    node *m = q.front;//save position ptr
    node *k = q.front;
    node *d = q.rear;
    int size=q.size, temp=n->next->data;
    for(int i=1;i<size;i++)
    {
        //cout<<" i = "<< i <<endl;
        int ps =i+1;
        n=m;
        if(n->data<= n->next->data)
        {
            m=m->next;
            n=m;
            continue;
        }
        n=n->next;
        while(n!=q.front && n->data < n->preverous->data)
        {
            {cout<< "before\n";
            cout<< "n = " << n <<endl;
            cout<< "m = " << m <<endl;
            cout<< "ps = "<< ps <<endl;
            k =q.front;
            d = q.rear;
            for(int j=0;j<size;j++)
            {
                cout<<&k->data<<" ";
                k= k->next;
            }
            cout<<endl;
            for(int j=0;j<size;j++)
            {
                cout<<&d->data<<" ";
                d = d->preverous;
            }
            cout<<endl;
            }

            ptr_switch(q, ps, ps-1);


            ps= ps-1;
            
            {cout<<"after\n";
            cout<< "n = " << n <<endl;
            cout<< "m = " << m <<endl;
            cout<< "ps = "<< ps <<endl;
            k =q.front;
            d = q.rear;
            for(int j=0;j<size;j++)
            {
                cout<<&k->data<<" ";
                k= k->next;
            }
            cout<<endl;
            for(int j=0;j<size;j++)
            {
                cout<<&d->data<<" ";
                d = d->preverous;
            }
            cout<<endl;
            }
            if(ps==1||n==q.front)break;

        }
        cout<<"\nwhile over\n";
        Display(q);
        cout<<endl;
        cout<<endl;

        

        /*int ps=i+1;
        if(i!=1)
        {
            if(n->data> n->next->data)m=n;
            else 
            {
                n = n->next;
                m=n;
                continue;
            }
            n = n->next;
            while( (n!=q.front) && (n->preverous->data > n->data) )
            {
                ptr_switch(q, ps, ps-1);
                ps-=1;
                
            }
            
            //if(m->next != q.rear){m=m->next;temp = m->next->data;}
            //else break;
            n=m;
        }
        else
        {
            if(n->data > temp)ptr_switch(q, i, i+1);
            else
            {
                n=n->next;
                }
            temp = n->next->data;
        }        
    }*/
    }
}