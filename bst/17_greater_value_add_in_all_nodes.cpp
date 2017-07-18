#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

void add_greater_values_in_nodes(node * root, int * value){
  if(!root) return;
  add_greater_values_in_nodes(root->right, value);
  root->value = root->value + *value;
  *value = root->value;
  add_greater_values_in_nodes(root->left, value);
}

int main(){
  node * bst = make_bst(40,1,100);
  inorder(bst);
  int value;
  value = 0;
  add_greater_values_in_nodes(bst, &value);
  inorder(bst);
}