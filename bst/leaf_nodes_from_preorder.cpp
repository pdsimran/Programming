#include <iostream>
#include <cstdio>

#include "../maker/bst.h"
#include "../maker/array.h"

using namespace std;

void print_leaf_nodes_from_preorder(int *preorder, int start, int end){
  if( start == end ){
    cout << preorder[start] << " ";
    return;
  }
  int i;
  if(preorder[start] > preorder[start+1]){
    for(i = start+1; i <= end; i++){
      if( preorder[start] < preorder[i] ) break;
    }
    print_leaf_nodes_from_preorder(preorder, start+1, i-1);
    if(i<= end) {
      print_leaf_nodes_from_preorder(preorder,i, end);
    }
  }else {
    print_leaf_nodes_from_preorder(preorder, start+1, end);
  }
}

int main(){
  int no_of_nodes;
  cin >> no_of_nodes;

  int preorder[no_of_nodes];
  for(int i = 0; i < no_of_nodes; i++){
    cin >> preorder[i];
  }
  cout << "Leaf Nodes Are : ";
  print_leaf_nodes_from_preorder(preorder, 0, no_of_nodes-1);
  cout << endl;
}