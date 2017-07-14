#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

int minimum_value_in_bst(node * root){
  node * previous = NULL;
  node * current = root;
  while(current){
    previous = current;
    current = current->left;
  }
  return previous->value;
}

int main(){
  node * bst = make_bst(1,1,100);
  int min = minimum_value_in_bst(bst);
  cout << "Minimum Value in BST = " << min << endl;
  inorder(bst);
}
