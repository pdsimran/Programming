#include <iostream>
#include <cstdio>

using namespace std;

#define SIZE 20

struct node {
	int value;
	struct node * left;
	struct node * right;
};

node * make_bst(int size = SIZE, int min = INT_MIN/2, int max = INT_MAX/2){
	int * values = make_array(size, min, max)
}

