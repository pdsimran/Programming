#include <iostream>
#include <cstdio>

using namespace std;

#define DEFAULT_SIZE 20

int * make_array(int size, int min = INT_MIN/2, int max = INT_MAX/2){
	int * output;
	srand (time(NULL));

	output = (int *)malloc(size*sizeof(int));
	for(int i = 0; i < size; i++ ){
		output[i] = min + rand()%(max-min+1);
	}

	return output;
}

void print_array(int * input, int size, string name = "Array"){
	cout << name << " : ";
	for(int i = 0; i < size; i++ ){
		cout << input[i] << " ";
	}
	cout << endl;
}
