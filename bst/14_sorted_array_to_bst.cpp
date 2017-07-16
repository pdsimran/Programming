#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

node * make_balanced_bst(int input[], int start, int end){
  if(start > end) return NULL;
  if(start == end){
    node * new_node = (node *)malloc(sizeof(node));
    new_node->value = input[start];
    new_node->left = new_node->right = NULL;
    return new_node;
  }
  node * new_node = (node *)malloc(sizeof(node));
  int mid = (start+end)/2;
  new_node->value = input[mid];
  new_node->left = make_balanced_bst(input, start, mid-1);
  new_node->right = make_balanced_bst(input, mid+1, end);
  return new_node;
}

int main(){
  int size = 1000;
  int input[size];
  for(int i = 0; i < size; i++){
    input[i] = i + 1;
  }
  node * balanced_bst = make_balanced_bst(input, 0, size-1);
  int height = binary_tree_height(balanced_bst);
  cout << "Height of balanced_bst is : " << height << endl;
}