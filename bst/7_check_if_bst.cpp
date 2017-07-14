#include <iostream>
#include <cstdio>
#include <climits>

#include "../maker/bst.h"

using namespace std;

// Wrong Approach
bool check_bst(node * root){
  if(!root) return true;
  bool output = true;
  if(root->left){
    output = (root->left->value < root->value) ? true : false;
    output &= check_bst(root->left);
  }
  if(root->right){
    output = (root->right->value > root->value) ? true : false;
    output &= check_bst(root->right);
  }
  return output;
}

bool check_bst2(node * root, int min, int max){
  if(!root) return true;
  if( (root->value < min) || (root->value > max) ){
    return false;
  }
  bool is_left_subtree_bst = check_bst2(root->left, min, root->value);
  bool is_right_subtree_bst = check_bst2(root->right, root->value, max);
  return is_left_subtree_bst && is_right_subtree_bst;
}

int main(){
  node * bst = make_bst(40,1,100);
  bool is_bst = check_bst2(bst, INT_MIN, INT_MAX);
  if(is_bst){
    cout << "Yes it's a BST" << endl;
  } else {
    cout << "Sorry! Given binary tree is not a BST" << endl;
  }
}

