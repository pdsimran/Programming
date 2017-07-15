#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

node * bst_minimum(node * root){
  node * previous = NULL;
  node * current = root;
  while(current){
    previous = current;
    current = current->left;
  }
  return previous;
}

node * successor(node * root, int key, node * succ){
  node * output;

  if(!root) return NULL;
  if(root->value == key){
    if(root->right != NULL){
      output =  bst_minimum(root->right);
    } else {
      output =  succ;
    }
  } else if(key < root->value){
    succ = root;
    output = successor(root->left, key, succ);
  } else if(key > root->value){
    output = successor(root->right, key, succ);
  }
  return output;
}

int main(){
  node * bst = make_bst(40,1,100);
  while(1){
    int key = 1+random()%99;
    node * found = bst_search(bst, key);
    if(found){
      node * succ;
      succ = successor(bst, key, succ);
      if(succ){
        cout << "Sucessor of " << key << " is " << succ->value << endl;
      } else {
        cout << "Sucessor of " << key << " is not found in the tree." << endl;
      }
      break;
    }
  }
}