#include <iostream>
#include <cstdio>
using namespace std;

#ifndef BST_H
#define BST_H

#include "binary_tree.h"
#include "array.h"

#define SIZE 20

node * bst_addition(node * root, int value){
	node * current = NULL;
	node * previous = NULL;
	node * new_node = NULL;

	if(root == NULL){
		new_node = (node *)malloc(sizeof(node));
		new_node->value = value;
		new_node->left = new_node->right = NULL;
		return new_node;
	}

	current = root;
	while(current != NULL){
		if (value < current->value){
			previous = current;
			current = current->left;
		} else if (value > current->value) {
			previous = current;
			current = current->right;
		} else if (value == current->value) {
			// Duplicates values are not supported.
			return root;
		}
	}

	new_node = (node *)malloc(sizeof(node));
	new_node->value = value;
	new_node->left = new_node->right = NULL;

	if (value < previous->value){
		previous->left = new_node;
	} else if (value > previous->value) {
		previous->right = new_node;
	}

	return root;
}

node * make_bst(int size = SIZE, int min = INT_MIN/2, int max = INT_MAX/2){
	int * values = make_array_unique(size, min, max);
	node * root = NULL;

	for( int i = 0; i < size; i++ ){
		root = bst_addition(root, values[i]);
	}
	return root;
}

node * bst_search(node * root, int value){
  node * current = NULL;
  current = root;
  while(current){
    if(value == current->value){
      return current;
    } else if (value < current->value){
      current = current->left;
    } else if (value > current->value){
      current = current->right;
    }
  }
  return current;
}

#endif