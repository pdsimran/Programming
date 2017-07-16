#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

void morris_traversal(node * root){
  node * previous = NULL;
  node * current = root;

  while(current){
    if(!current->left){
      cout << current->value << " ";
      current = current->right;
    } else {
      previous = current->left;
      while(previous->right){
        previous = previous->right;
      }
      previous->right = current;
      current = current->left;
      previous->right->left = NULL;
    }
  }
}

int main(){
  node * bst = make_bst(40,1,100);
  inorder(bst);
  cout << "Morris Traversal : ";
  morris_traversal(bst);
  cout << endl;
}