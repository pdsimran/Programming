#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>

#include "../maker/bst.h"

using namespace std;

struct data{
  int node_count;
  bool is_bst;
  int min;
  int max;
};

data largest_bst(node * root){
  data output;
  if(!root){
    output.node_count = 0;
    output.is_bst = true;
    output.min = INT_MAX;
    output.max = INT_MIN;
    return output;
  }
  if((!root->left) && (!root->right)){
    output.node_count = 1;
    output.is_bst = true;
    output.min = root->value;
    output.max = root->value;
    return output;
  }
  data left_output = largest_bst(root->left);
  data right_output = largest_bst(root->right);
  if(left_output.is_bst && right_output.is_bst && left_output.max < root->value && root->value < right_output.min){
    output.node_count = left_output.node_count + right_output.node_count + 1;
    output.is_bst = true;
    output.min = min(left_output.min, root->value);
    output.max = max(right_output.max, root->value);
  } else {
    output.is_bst = false;
    output.node_count = max(left_output.node_count, right_output.node_count);
  }
  return output;
}

int main(){
  node * bst = make_bst(40,1,100);
  inorder(bst);
  cout << "root = " << bst->value << endl;
  data max_bst_node = largest_bst(bst);
  if(max_bst_node.is_bst){
    cout << "Tree is BST with " << max_bst_node.node_count << " nodes." << endl;
  }
  // cout << max_bst_node.is_bst << " " << max_bst_node.node_count << " " << max_bst_node.min << " " << max_bst_node.max << " " <<  endl;
}