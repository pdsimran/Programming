#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

// maintain count of left subtree nodes at each nodes.
// Since we need BST and a new addition function so for now 
// I am using this count function. and Assuming bst_node_count 
// is giving count in O(1)
int bst_node_count(node * root){
  if(!root) return 0;
  return 1 + bst_node_count(root->left) + bst_node_count(root->right);
}

int kth_smallest(node * root, int k){
  int left_count = bst_node_count(root->left);
  int ans;
  if(left_count == k-1){
    ans = root->value;
  } else if( left_count < k-1 ){
    ans = kth_smallest(root->right, k-(left_count+1));
  } else if ( left_count > k-1 ){
    ans = kth_smallest(root->left, k);
  }
  return ans;
}

int main(){
  node * bst = make_bst(40,1,100);
  cout << "Enter the k : ";
  int k;
  cin >> k;
  int ans = kth_smallest(bst, k);
  cout << "The " << k << "th smallest value in the BST is " << ans << endl;
  inorder(bst);
}