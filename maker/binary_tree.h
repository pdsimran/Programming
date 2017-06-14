#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
	int value;
	struct node * left;
	struct node * right;
};

void inorder_traversal(node * root){
	if (root == NULL) return;
	inorder_traversal(root->left);
	cout << root->value << " ";
	inorder_traversal(root->right);
}

void inorder(node * root){
	cout << "Inorder : ";
	inorder_traversal(root);
	cout << endl;
}