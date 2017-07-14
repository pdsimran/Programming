#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

struct data{
  node * predecessor;
  node * successor;
};

node * minimum_in_bst(node * root){
  node * previous = NULL;
  node * current = root;
  while(current){
    previous = current;
    current = current->left;
  }
  return previous;
}

node * maximum_in_bst(node * root){
  node * previous = NULL;
  node * current = root;
  while(current){
    previous = current;
    current = current->right;
  }
  return previous;
}

data * predecessor_successor(node * root, int key, data * output){
  if(root == NULL){
    return output;
  }

  if(root->value == key){
    if(root->left){
      output->predecessor = maximum_in_bst(root->left);
    }
    if(root->right){
      output->successor = minimum_in_bst(root->right);
    }
    return output;
  } else if (key < root->value){
    output->successor = root;
    output = predecessor_successor(root->left, key, output);
  } else if (key > root->value){
    output->predecessor = root;
    output = predecessor_successor(root->right, key, output);
  }
  return output;
}

int main(){
  node * bst = make_bst(40, 1, 50);
  data * output = (data *)malloc(sizeof(data));
  int key = 1+rand()%50;
  inorder(bst);
  cout << "Searching key = " << key << endl;
  data * answer = predecessor_successor(bst, key, output);
  cout << "predecessor = " << answer->predecessor->value << "  key = " << key << "  successor = " << answer->successor->value << endl;
}