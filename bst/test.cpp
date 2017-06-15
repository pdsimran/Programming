#include <iostream>
#include <cstdlib>

#include "../maker/array.h"
#include "../maker/bst.h"

using namespace std;

int main(){
	node * bst = make_bst(40, 1, 100);
	inorder(bst);
}