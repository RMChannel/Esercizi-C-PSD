#include <stdio.h>
#define N 10
#define TRUE 1
#define FALSE 0

void inputArray(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}

void outputArray(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int minimo(int *a, int n){
	int i;
	int min = 0;
	for(i=1; i<n; i++){
			if (a[i]<a[min])
				min = i;
	}
	return min;
}

void swap(int *a, int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

void selectionSort(int *a, int n){
	int i, min;
	for(i=0; i<n-1; i++){
		min = minimo(a+i, n-i)+i;
		swap(&a[min], &a[i]);
	}
}

void insertSortedArray(int *a, int *n, int val) {
    int i;
    for (i=*n;i>0 && val<a[i-1];i--) {
        a[i]=a[i-1];
    }
    a[i]=val;
    (*n)++;
}

void insertionSort(int *a, int n) {
	for (int i=1;i<n;) {
		insertSortedArray(a,&i,a[i]);
	}
}

void bubbleSort(int *a, int n) {
	for (int i=1;i<n;i++)
		for (int j=0;j<(n-i);j++)
			if (a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
}

int adaptiveBubbleSort(int *a, int n) {
	int ordinato=FALSE;
	int operazioni=0;
	for (int i=1;i<n && !ordinato;i++) {
		ordinato=TRUE;
		for (int j=0;j<(n-i);j++) {
			operazioni++;
			if (a[j]>a[j+1]) {
				swap(&a[j],&a[j+1]);
				ordinato=FALSE;
			}
		}
	}
	return operazioni;
}

int binarySearch(int *a, int n, int elem) {
	int begin=0, end=n-1, center;
	while (end>=begin) {
		center=(end+begin)/2;
		if (a[center]==elem) return center;
		else if (a[center]<elem) {
			begin=center+1;
		}
		else {
			end=center-1;
		}
	}
	return -1;
}

int main()
{
	int array[N];
	int n = 5;
	int val;
	inputArray(array, n);
	printf("Inserisci il numero da cercare: ");
	scanf("%d",&val);
	printf("Posizione: %d\n", binarySearch(array,n,val));
	//outputArray(array, n);

	return 0;
}
