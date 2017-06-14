#include <iostream>
#include <cstdio>

#include "binary_tree.h"
#include "array.h"

using namespace std;

#define SIZE 20

node * bst_addition(node * root, int value){
	node * current;

	if (root == NULL){
		node * new_node = (node *)malloc(sizeof(node));
		new_node->value = value;
		return new_node;
	}
	current = root;
	while(current != NULL){
		if (value < current->value) current = current->left;
		if (value > current->value) current = current->right;
		// Duplicates values are not supported.
		if (value == current->value) return root;
	}
	current = (node *)malloc(sizeof(node));
	current->value = value;
	return root;
}

node * make_bst(int size = SIZE, int min = INT_MIN/2, int max = INT_MAX/2){
	int * values = make_array(size, min, max);
	node * root;

	for( int i = 0; i < size; i++ ){
		root = bst_addition(root, values[i]);
	}
	return root;
}