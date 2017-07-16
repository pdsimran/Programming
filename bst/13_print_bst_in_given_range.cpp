#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

void print_keys_within_range(node * root, int k1, int k2){
  if(!root) return;
  if (!(k1 > root->value)) print_keys_within_range(root->left, k1, k2);
  if( k1 <= root->value && root->value <= k2) cout << root->value << " ";
  if (!(k2 < root->value)) print_keys_within_range(root->right, k1, k2);
}

int main(){
  node * bst = make_bst(40,1,100);
  int k1, k2;
  cout << "Enter the value of k1 and k2 : ";
  cin >> k1 >> k2;
  cout << "Keys within range [" << k1 << ", " << k2 << "] : ";
  print_keys_within_range(bst, k1, k2);
  cout << endl;
  inorder(bst);
}