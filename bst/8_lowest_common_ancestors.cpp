#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

node * compute_lca(node * root, int first, int second){
  if(!root) return NULL;

  if( first == root->value || second == root->value){
    return root;
  }

  if(first < root->value && second < root->value){
    return compute_lca(root->left, first, second);
  }

  if(first > root->value && second > root->value){
    return compute_lca(root->right, first, second);
  } 
  return root;
}

int main(){
  node * bst = make_bst(40,1,100);
  int first;
  int second;
  while(1){
    first = 1+rand()%50;
    second = 1+rand()%50;
    if( bst_search(bst, first) && bst_search(bst, second)) break;
  }
  node * lca = compute_lca(bst, first, second);
  cout << "Path of " << first << " : ";
  print_path(bst, first);
  cout << "Path of " << second << " : ";
  print_path(bst, second);
  cout << "LCA of " << first << " and " << second << " is " << lca->value << endl;
}

