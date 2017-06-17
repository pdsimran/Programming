#include <iostream>
#include <cstdio>

#include "../maker/bst.h"
#include "../maker/array.h"

using namespace std;

node * add_reservation(node * root, int reservation_time, int job_time){
  if(!root){
    node * new_node = (node *)malloc(sizeof(node));
    new_node->left = new_node->right = NULL;
    new_node->value = reservation_time;
    return new_node;
  }
  if( reservation_time >= root->value-job_time && reservation_time <= root->value+job_time){
    return root;
  } else if( reservation_time < root->value ){
    root->left = add_reservation(root->left, reservation_time, job_time);
  } else if(reservation_time > root->value){
    root->right = add_reservation(root->right, reservation_time, job_time);
  }
  return root;
}

int main(){
  node * bst = NULL;
  int no_of_jobs;
  int job_time;

  cin >> no_of_jobs >> job_time;
  int reservation_time;
  for(int i = 0; i < no_of_jobs; i++){
    cin >> reservation_time;
    bst = add_reservation(bst, reservation_time, job_time);
  }
  inorder(bst);
}