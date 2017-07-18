#include <iostream>
#include <cstdio>

#include "../maker/bst.h"

using namespace std;

void function1(node * one){
  cout << "one(func) = " << one << endl;
  one = one->left;
  cout << "one(func) = " << one << endl;
}

void function2(node * one){
  one->value = 10;
  cout << "one->value(func) = " << one->value << endl;
}

void function3(node * one){
  one->left = NULL;
  if(!one->left){
    cout << "func - Yes one->left is null now." << endl;
  } else{
    cout << "func - Nope. one->left is not null still" << endl;
  }
}

int main(){
  node * one = (node *)malloc(sizeof(node));
  node * two = (node *)malloc(sizeof(node));
  one->value = 1; one->left = two; one->right = NULL;
  two->value = 2;

  cout << "one(Main) = " << one << endl;
  function1(one);
  cout << "one(Main) = " << one << endl;

  cout << "*****************************************************" << endl;  

  cout << "one->value(Main) = " << one->value << endl;
  function2(one);
  cout << "one->value(Main) = " << one->value << endl;

  cout << "*****************************************************" << endl;

  function3(one);
  if(!one->left){
    cout << "Main - Yes one->left is null now." << endl;
  } else{
    cout << "Main - Nope. one->left is not null still" << endl;
  }
}