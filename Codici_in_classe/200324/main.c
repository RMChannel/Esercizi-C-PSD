#include "array.h"
#include "item.h"

#define N 10

int main(){

	Item array[N];
	int n = 2;
	int val;
	inputArray(array, n);
	bubbleSort(array,n);
	outputArray(array,n);

	return 0;
}