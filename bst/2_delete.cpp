#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

bool is_leaf(node * temp){
  if(temp->left == NULL && temp->right == NULL) return true;
  else return false;
}

node * max_node(node * root){
  if(root == NULL) return NULL;
  else if(root->right == NULL) return root;
  else return max_node(root->right);
}

node * min_node(node * root){
  if(root == NULL) return NULL;
  else if (root->left == NULL) return root;
  else return min_node(root->left);
}

node * deletion(node * root, int value){
  node * current = NULL;
  node * previous = NULL;
  current = root;
  
  while(current){
    if( value < current->value ){
      previous = current;
      current = current->left;
    } else if(value > current->value){
      previous = current;
      current = current->right;
    } else if(value == current->value){
      break;
    }
  }
  if(!current) return root; // value not found in the tree.

  if(is_leaf(current)){
    if(value != root-> value){
      node ** temp = (previous->left == current) ? &(previous->left) : &(previous->right);
      *temp = NULL;
    } else {
      root = NULL;
    }
  } else if( (current->left == NULL) || (current->right == NULL) ){
    node * replace_by = (current->left == NULL) ? (current->right) : (current->left);
    if (value != root->value){
      node ** parent = (previous->left == current) ? &(previous->left) : &(previous->right);
      *parent = replace_by;
    } else {
      root = replace_by;
    }
  } else {
    node * predecessor = current->left;
    node * predecessor_previous = current;

    if(!predecessor->right){
      predecessor->right = current->right;
    } else {
      while(predecessor->right){
        predecessor_previous = predecessor;
        predecessor = predecessor->right;
      }
      predecessor_previous->right = predecessor->left;
      predecessor->left = current->left;
      predecessor->right = current->right;
    }
    if( value != root->value){
      node ** parent = (previous->left == current) ? &(previous->left) : &(previous->right);
      *parent = predecessor;
    } else {
      root = predecessor;
    }
  }
  current = NULL;
  free(current);
  inorder(root);
  return root;
}

int main(){
  node * bst = make_bst(40, 1, 100);
  inorder(bst);
  srand(time(NULL));
  int count = 0;
  while(bst){
    int temp = 1 + rand()%100;
    bst = deletion(bst, temp);
    count++;
    if(count == 400) break;
  }
}