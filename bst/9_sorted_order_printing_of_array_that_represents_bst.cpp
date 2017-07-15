#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

void inorder(int arr[], int start, int end){
  if(start > end) return;
  inorder(arr, 2*start+1, end);
  cout << arr[start] << " ";
  inorder(arr, 2*start+2, end);
}

int main(){
  int input[] = {4, 2, 5, 1, 3};
  int size = sizeof(input)/sizeof(int);
  cout << "Inorder : ";
  inorder(input, 0, size-1);
  cout << endl;
}