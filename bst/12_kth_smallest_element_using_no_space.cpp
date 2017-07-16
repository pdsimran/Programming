#include <iostream>
#include <cstdio>
#include <climits>

#include "../maker/bst.h"

using namespace std;

int morris_traversal(node * root, int k){
  node * previous = NULL;
  node * current = root;
  int kth_smallest = INT_MIN;
  int count = 0;

  while(current){
    if(!current->left){
      count += 1;
      if(count == k) kth_smallest = current->value;
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
  return kth_smallest;
}

int main(){
  int k;
  cout << "Enter the value of k : ";
  cin >> k;
  node * bst = make_bst(40,1,100);
  inorder(bst);
  int kth_smallest = morris_traversal(bst, k);
  cout << k << "th_smallest in the tree is : " << kth_smallest << endl;
}