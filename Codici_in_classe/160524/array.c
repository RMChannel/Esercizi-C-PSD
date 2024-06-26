#include <stdio.h>
#define N 100
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
	int i,j,k, copia[n1+n2]; //Ci creiamo 3 contatori, insieme ad un array di dimensione uguale alla somma delle dimensioni degli array passati
	for(i=0,j=0,k=0;i<n1 && j<n2;k++) { //Scorriamo l'array copia, così da salvare in modo ordinato gli elementi degli array passati
		if (a1[i]<=a2[j]) { //Se l'elemento del 1°array è minore o uguale a quello del 2°, allora copia il 1° e scorro avanti
			copia[k]=a1[i];
			i++;
		}
		else { //In caso contrario, prendo l'elemento del 2°array
			copia[k]=a2[j];
			j++;
		}
	}
	for(;i<n1;i++,k++) copia[k]=a1[i]; //Dopo aver preso tutti gli elementi dal ciclo di prima, potrebbe accadere che uno degli array abbia elementi in più rispetto all'altro
	for(;j<n2;j++,k++) copia[k]=a2[j]; //E per risolvere il problema, facciamo una copia di tutti gli elementi rimanenti nell'array copia
	for(k=0;k<(n1+n2);k++) { //Poi, ricordiamo che noi passiamo alla funzione anche un array a (dove viene salvato l'array formato dall'insieme degli altri 2)
		a[k]=copia[k]; //Allora copiamo in a l'array copia
	}
}

void mergeSort(int a[], int n) {
	if (n>1) { //Controllo che il numero degli elementi è maggiore di 1
		mergeSort(a,n/2); //Se si, allora richiamo la stessa funzione, però con la metà a sinistra
		mergeSort(a+(n/2),(n-(n/2)));//Richiamo la stessa funzione, ma con la metà a destra
		merge(a,(a+(n/2)),n/2,(n-(n/2)),a); //Infine facciamo il merge tra i due sottoarray formati (questo ogni volta dopo aver diviso tutti i sottoarray)
	}
}

/*
Questa funzione si occupa di trovare il pivot (attraverso la ricerca della media dei 3 e di fare lo scambio tra i due elementi first e last e restituisce il nuovo pivot.
Essa prende in input l'array, l'elemento iniziale e quello finale
*/
int partition(int a[], int first, int last) {
	int i=first-1, j=last+1, pivot=a[first]; //Incrementiamo/Decremntiamo last e first perché li incrementiamo o decrementiamo poi nel ciclo almeno una volta
	while(1) {
		do {
			j--; //Decrementiamo j finché il valore corrispondente non è maggiore al pivot
		} while(a[j]>pivot);
		do {
			i++; //Incrementiamo i finché il valore corrispondente non è minore al pivot
		} while(a[i]<pivot);
		if (i>=j) return j; //Nel caso i e j si incontrano, terminiamo e restituiamo j
		swap(&a[i],&a[j]); //Ogni volta che facciamo questo ciclo, fai lo swap tra a[i] e a[j]
	}
}

/*
Questa funziona è quella che svolge il lavoro di QuickSort.
Prende in input l'array da ordinare, l'indice del 1°elemento e l'indice dell'ultimo elemento (all'inizio corrispondono con quelli dell'array, poi ai vari richiami corrispondono agli indirizzi dei sotto-array)
*/
void qSort(int a[], int first, int last) {
	if (first<last) { //Se l'indice dell'inizio e della fine non si sono incontrati ancora
		int pivot=partition(a,first,last); //Allora chiamo partition
		qSort(a,first,pivot); //E richiamo il quicksort al sottoarray sinistro
		qSort(a,pivot+1,last); //E richiamo il quicksort al sottoarray destro
	}
}

void quickSort(int a[], int n) { //Funzione di richiamo per la vera funzione di quickSort
	qSort(a,0,n-1);
}

int main(){
	int a[N]={100, 99, 98, 97, 95, 94, 93, 92, 91, 90, 89, 88, 87, 82, 81, 80, 79, 78, 77, 76, 75, 74, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 46, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	//inputArray(a,N);
	quickSort(a,N);
	outputArray(a,N);
	return 0;
}

