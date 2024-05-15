#include <stdio.h>
#define N 5
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


//f(n) = O(n) = Omega(n) = Theta(n)
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

//f(n)= O(n2) = Omega(n2) = Theta(n2)
void selectionSort(int *a, int n){
	int i, min;
	for(i=0; i<n-1; i++){
		min = minimo(a+i, n-i)+i;
		swap(&a[min], &a[i]);
	}
}

//f(n) = O(n) = Omega(1)
void insertSortedArray(int *a, int *n, int val) {
    int i;
    for (i=*n;i>0 && val<a[i-1];i--) {
        a[i]=a[i-1];
    }
    a[i]=val;
    (*n)++;
}

//f(n) = n*O(n) = O(n2) = n* Omega(1) = Omega(n)
//caso peggiore: quadratica; caso migliore: lineare
void insertionSort(int *a, int n) {
	for (int i=1;i<n;) {
		insertSortedArray(a,&i,a[i]);
	}
}

//f(n) = Theta(n2)
void bubbleSort(int *a, int n) {
	for (int i=1;i<n;i++)
		for (int j=0;j<(n-i);j++)
			if (a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
}

//f(n) = O(n2) = Omega(n)
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

//O(log(n)) = Omega(1)
int binarySearch(int *a, int n, int elem){
	//variabili index
	int begin = 0, end = n-1, center;

	while(end >= begin){
		center = (end + begin)/2;
		if(elem == a[center]){
				return center;
		}else if(elem < a[center]){
			end = center - 1;
		}else{
			begin = center + 1;
		}
	}
	return -1;
}

//f(n) = f(n/2)+c 
int ricercaBinRic(int a[], int inf, int sup, int elem) {
	if(inf>sup)
		return -1;
	int center = (inf+sup)/2;
	if(elem==a[center])
		return center;
	else if (elem>a[center])
		return ricercaBinRic(a, center+1, sup, elem);
	else
		return ricercaBinRic(a, inf, center-1, elem);
}

int ricercaBinariaR(int a[], int n, int elem) {
	return ricercaBinRic(a, 0, n-1, elem);
}

void merge(int a1[], int a2[],int n1, int n2, int a[]) {
	int i,j,k, copia[n1+n2];
	for(i=0,j=0,k=0;i<n1 && j<n2;k++) {
		if (a1[i]<=a2[j]) {
			copia[k]=a1[i];
			i++;
		}
		else {
			copia[k]=a2[j];
			j++;
		}
	}
	for(;i<n1;i++,k++) copia[k]=a1[i];
	for(;j<n2;j++,k++) copia[k]=a2[j];
	for(k=0;k<(n1+n2);k++) {
		a[k]=copia[k];
	}
}

void mergeSort(int a[], int n) {
	if (n>1) {
		mergeSort(a,n/2);
		mergeSort(a+(n/2),(n-(n/2)));
		merge(a,(a+(n/2)),n/2,(n-(n/2)),a);
	}
}

int main(){
	int a[N];
	inputArray(a,N);
	mergeSort(a,N);
	outputArray(a,N);
	return 0;
}

