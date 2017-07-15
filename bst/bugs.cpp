#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

void function1(node * one){
  cout << "one(func) = " << one << endl;
  one = one->left;
  cout << "one(func) = " << one << endl;
}

int main(){
  node * one = (node *)malloc(sizeof(node));
  node * two = (node *)malloc(sizeof(node));
  one->value = 1; one->left = two; one->right = NULL;
  two->value = 2;

  cout << "one(Main) = " << one << endl;
  function1(one);
  cout << "one(Main) = " << one << endl;
}