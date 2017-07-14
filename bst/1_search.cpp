#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

node * search(node * root, int value){
  node * current = NULL;
  current = root;
  while(current){
    if(value == current->value){
      return current;
    } else if (value < current->value){
      current = current->left;
    } else if (value > current->value){
      current = current->right;
    }
  }
  return current;
}

int main(){
  node * bst = make_bst(40, 1, 100);
  inorder(bst);
  srand (time(NULL));

  for(int i = 0; i < 5; i++ ){
    int value = rand()%100;
    node * found = search(bst, value);
    if(found){
      cout << "Value - " << value << " is found in the bst" << endl;
    } else {
      cout << "Value - " << value << " is not found in the bst" << endl;
    }
  }

}

