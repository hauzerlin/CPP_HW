#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "tree_func.h"

using namespace std;

//new function 需要丟一個空的TreeNode ***沒有遞迴只執行一次會失敗
void restruct_tree(TreeNodePtr *treePtr, queue_post Queue)
{
   if (*treePtr == NULL) { // if tree is empty
      *treePtr = new TreeNode;

      if (*treePtr != NULL) { // if memory was allocated, then assign data
        (*treePtr)->operate = Queue.rear->item;
        (*treePtr)->leftPtr = NULL;
        (*treePtr)->rightPtr = NULL;
      }
      else {
         cout<< Queue.first->item <<" not inserted. No memory available.\n";
      }
   }
   else { // tree is not empty
      restruct(*treePtr, Queue.rear->prev);
   }
}

//link nodes方向與預設相反 要從尾巴回來
linknode* restruct(treeNode *treePtr, linknode *node)
{
   treeNode *ptr = new treeNode;
   treeNode *now = treePtr;
   linknode *temp = node;
   if(Num_or_OP(node->item))//如果item是operator，向右插入並進入下一層
   {
      treePtr->rightPtr = ptr;
      ptr->operate = temp->item;
      ptr->leftPtr = NULL;
      ptr->rightPtr = NULL;

      temp = restruct((treePtr)->rightPtr, node->prev);
      //cout<<"temp op1: "<<temp->item<<endl;
      //cout<<"treePtr: "<<treePtr->operate<<endl;
   }
   else //如果item是operand，向右插入接著回到上一層
   {
      treePtr->rightPtr = ptr;
      ptr->operate = node ->item;
      ptr->leftPtr = NULL;
      ptr->rightPtr = NULL;

      //cout<<"temp num1: "<<temp->item<<endl;
      //cout<<"treePtr: "<<treePtr->operate<<endl;
      temp=  node->prev;
   }
   //向左插入
   treeNode *ptr_left = new treeNode;
   
   //now = treePtr->rightPtr;
   treePtr->leftPtr = ptr_left;
   ptr_left->operate = temp->item;
   ptr_left ->rightPtr = NULL;
   ptr_left ->leftPtr = NULL;

   //cout<<"ptr_left: "<<ptr_left->operate<<endl;
   if(Num_or_OP(temp->item))
   {
      temp = restruct(ptr_left, temp->prev);
      //cout<<"temp op2: "<<temp->item<<endl;
   }
   else
   {
      //ptr_left->leftPtr = NULL;
      //cout<<"temp treePtr: "<<treePtr->operate<<endl;
      //cout<<"temp: "<<temp->item<<endl;
      if(temp->prev!=NULL) return temp->prev;
   }
   return temp;
   //restruct_tree()
}

// begin inorder traversal of tree
void postOrder(TreeNodePtr treePtr) {
   // if tree is not empty, then traverse
   if (treePtr != NULL) {
      postOrder(treePtr->leftPtr);
      postOrder(treePtr->rightPtr);
	  cout<<left<<setw(2)<<treePtr->operate;
   }
}
//to tell item is a number or a operater.
bool Num_or_OP(string item)
{
   if(item[0]<48 || item[0]>57)return 1;
   else return 0;
}

void M1(queue_post &Queue, string n1, string n2)
{
   if(Num_or_OP(n1)||Num_or_OP(n2))
   {
      cerr<<"Wrong format!!!"<<endl;
      return;
   }
   if(Link_node_Switch(Queue, n1, n2))return;
   else
      cerr<<"Somethin wrong with operator."<<endl;
}

void M2(queue_post &Queue, int num)
{
   linknode *ptr = Queue.first;
   string NUM = to_string(num);
   int postion=0;

   if(num>Queue.num)
   {
      cerr<<"wrong format"<<endl;
      exit(-1);
   }

   while(ptr!=NULL)
   {
      //if(!NUM.compare(ptr->item))break;
      if(Num_or_OP(ptr->item)){
         while(Num_or_OP(ptr->next->item))ptr= ptr->next;
         postion++;
         }
      else {
         ptr=ptr->next;
         continue;
      }
      if(num==postion)break;
      ptr = ptr->next;
   }

   if(ptr==NULL)
   {
      cerr<<"ERROR!!!"<<endl;
      return;}

   while(Num_or_OP(ptr->item)){
   if(ptr->item[0]=='V')ptr->item="H";
   else if(ptr->item[0]=='H')ptr->item="V";
   else cerr<<"wrong node postion."<<endl;
   ptr= ptr->next;}

   //cout<<"postion: "<<postion<<endl;
   //cout<<"ptr->item: "<<ptr->item<<endl;
   return ;
}

void M3(queue_post &Queue, string num, string op1)
{
   linknode *ptr = Queue.first;
   int postion=0, NUM=atoi(op1.c_str());
   while(ptr!=NULL)
   {
      if(Num_or_OP(ptr->item))postion++;
      else 
      {
         ptr= ptr->next;
         continue;
      }
      if(postion==NUM)break;
      ptr= ptr->next;
   }

   if(ptr==NULL)
   {
      cerr<<"Wrong!!!"<<endl;
      return ;
   }

   if(Link_node_Switch(Queue, ptr, num))return;
   else 
   cerr<<"Swith action M3 ERROR!!!"<<endl;
}

//For M3
bool Link_node_Switch(queue_post &q, linknode *op, std::string num)
{   
   linknode *n = q.first;
   linknode *n1 = NULL, *n2 = op;

   while(n1==NULL && n!=NULL )
   {
      if(!num.compare(n->item))n1 =n;
      n = n->next;
   }

   if(n1==NULL || n2==NULL)return 0;

   //如果n1與n2相隔壁
   if(n1->next == n2)
   {
      //讓n1前一個node的next指向n2
      if(n1!=q.first)
      {
         n=n1->prev;
         n->next = n2;
      }
      else q.first = n2;

      //讓n2下一個node的prev指向n1
      if(n2!=q.rear)
      {
         n=n2->next;
         n->prev = n1;
      }
      else q.rear = n1;

      n= n2->next;
      n2->next = n1;
      n1->next = n;

      n = n1->prev;
      n1->prev = n2;
      n2->prev = n;
   }

   else if(n1->prev == n2)
   {
      //讓n1前一個node的next指向n2
      if(n2!=q.first)
      {
         n=n2->prev;
         n->next = n1;
      }
      else q.first = n1;

      //讓n2下一個node的prev指向n1
      if(n1!=q.rear)
      {
         n=n1->next;
         n->prev = n2;
      }
      else q.rear = n2;

      n= n1->next;
      n1->next = n2;
      n2->next = n;

      n = n2->prev;
      n2->prev = n1;
      n1->prev = n;
   }
   else 
   {
      if(n1==q.first)
      {
         q.first = n2;
         if(n2 ==q.rear)q.rear = n1;
         else {
            n = n2->next;
            n->prev = n1;}

         n2->prev->next = n1;
         n1->next->prev = n2;

         n= n2->next;
         n2->next = n1->next;
         n1->next = n;

         n = n2->prev;
         n2->prev = n1->prev;
         n1->prev = n;
   }
   else if(n2 == q.first)
   {
      q.first = n1;
      if(n1 ==q.rear)q.rear = n2;
      else{
         n = n1->next;
         n->prev = n2;}

      n1->prev->next = n2;
      n2->next->prev = n1;

      n= n1->next;
      n1->next = n2->next;
      n2->next = n;

      n = n1->prev;
      n1->prev = n2->prev;
      n2->prev = n;
   }
   else
   {
      if(n1==q.rear)
      {
         q.rear = n2;
         n2->next->prev = n1;
      }
      else if(n2==q.rear)
      {
         q.rear = n1;
         n1->next->prev = n2;
      }
      else{
         n1->next->prev = n2;
         n2->next->prev = n1;
      }
         n1->prev->next = n2;
         n2->prev->next = n1;

         n= n1->next;
         n1->next = n2->next;
         n2->next = n;

         n = n1->prev;
         n1->prev = n2->prev;
         n2->prev = n;
      }
   }  
   return 1;
}

//for M1
bool Link_node_Switch(queue_post &q, std::string num1, std::string num2)
{
   if(!num1.compare(num2))return 0;
   
   linknode *n = q.first;
   linknode *n1 = NULL, *n2 = NULL;
   string num;

   while(n1==NULL || n2==NULL && n!=NULL )
   {
      if(!num1.compare(n->item))n1 =n;
      else if(!num2.compare(n->item))n2 = n;
      n = n->next;
   }

   if(n1==NULL || n2==NULL)return 0;

   //如果n1與n2相隔壁
   if(n1->next == n2)
   {
      //讓n1前一個node的next指向n2
      if(n1!=q.first){
         n=n1->prev;
         n->next = n2;}
      else q.first = n2;

      //讓n2下一個node的prev指向n1
      if(n2!=q.rear){
         n=n2->next;
         n->prev = n1;}
      else q.rear = n1;

      n= n2->next;
      n2->next = n1;
      n1->next = n;

      n = n1->prev;
      n1->prev = n2;
      n2->prev = n;

   }

   else if(n1->prev == n2)
   {
      //讓n1前一個node的next指向n2
      if(n2!=q.first){
         n=n2->prev;
         n->next = n1;}
      else q.first = n1;

      //讓n2下一個node的prev指向n1
      if(n1!=q.rear){
         n=n1->next;
         n->prev = n2;}
      else q.rear = n2;

      n= n1->next;
      n1->next = n2;
      n2->next = n;

      n = n2->prev;
      n2->prev = n1;
      n1->prev = n;

   }
   else 
   {
      if(n1==q.first)
      {
         q.first = n2;
         if(n2 ==q.rear)q.rear = n1;
         else 
         {
            n = n2->next;
            n->prev = n1;
         }

         n2->prev->next = n1;
         n1->next->prev = n2;

         n= n2->next;
         n2->next = n1->next;
         n1->next = n;

         n = n2->prev;
         n2->prev = n1->prev;
         n1->prev = n;
   }
   else if(n2 == q.first)
   {
      q.first = n1;
      if(n1 ==q.rear)q.rear = n2;
      else 
      {
         n = n1->next;
         n->prev = n2;
      }

      n1->prev->next = n2;
      n2->next->prev = n1;

      n= n1->next;
      n1->next = n2->next;
      n2->next = n;

      n = n1->prev;
      n1->prev = n2->prev;
      n2->prev = n;
   }
   else
   {
      if(n1==q.rear)
      {
         q.rear = n2;
         n2->next->prev = n1;
      }
      else if(n2==q.rear)
      {
         q.rear = n1;
         n1->next->prev = n2;
      }
      else{
         n1->next->prev = n2;
         n2->next->prev = n1;
      }
         n1->prev->next = n2;
         n2->prev->next = n1;

         n= n1->next;
         n1->next = n2->next;
         n2->next = n;

         n = n1->prev;
         n1->prev = n2->prev;
         n2->prev = n;
      }
   }  
   return 1;
}