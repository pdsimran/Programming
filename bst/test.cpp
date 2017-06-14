#include <iostream>
#include <cstdlib>

#include "../maker/array.h"
#include "../maker/bst.h"

using namespace std;

int main(){
	node * bst = make_bst(20, 1, 50);
	inorder(bst);
}