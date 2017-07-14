#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

void inorder_with_array(node * root, int * inorder){
  static int index = 0;
  if(!root) return;
  inorder_with_array(root->left, inorder);
  inorder[index] = root->value;
  index++;
  inorder_with_array(root->right, inorder);
}

int main(){
  node * bst = make_bst(40,1,100);
  int * output = (int *)malloc(sizeof(int)*40);
  inorder_with_array(bst, output);
  cout << "Inorder : ";
  for(int i = 0; i < 40; i++ ){
    cout << output[i] << " ";
  }
  cout << endl;
}