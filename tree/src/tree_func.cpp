#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "tree_func.h"

using namespace std;

void insertNode(TreeNodePtr *treePtr, int value)
{
    if (*treePtr == NULL) { // if tree is empty
      *treePtr = new TreeNode;

      if (*treePtr != NULL) { // if memory was allocated, then assign data
        (*treePtr)->data = value;
        (*treePtr)->leftPtr = NULL;
        (*treePtr)->rightPtr = NULL;
      }
      else {
         cout<<value<<" not inserted. No memory available.\n";
      }
   }
   else { // tree is not empty
      // data to insert is less than data in current node
      if (value < (*treePtr)->data) {
         insertNode(&((*treePtr)->leftPtr), value);
      }

      // data to insert is greater than data in current node
      else if (value > (*treePtr)->data) {
         insertNode(&((*treePtr)->rightPtr), value);
      }
      else { // duplicate data value ignored
         cout<<"dup";
      }
   }
}

// begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr) {
   // if tree is not empty, then traverse
   if (treePtr != NULL) {
      inOrder(treePtr->leftPtr);
      cout<<setw(3)<<treePtr->data;
      inOrder(treePtr->rightPtr);
   }
}