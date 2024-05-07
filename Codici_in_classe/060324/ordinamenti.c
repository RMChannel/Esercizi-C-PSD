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

int minimo(int *a, int n){ //SPIEGATO IN UN ALTRO FILE
	int i;
	int min = 0;
	for(i=1; i<n; i++){
			if (a[i]<a[min])
				min = i;
	}
	return min;
}

void swap(int *a, int *b){ //SPIEGATO IN UN ALTRO FILE
	int temp = *a;
	*a=*b;
	*b=temp;
}

void selectionSort(int *a, int n){ //SPIEGATO IN UN ALTRO FILE
	int i, min;
	for(i=0; i<n-1; i++){
		min = minimo(a+i, n-i)+i;
		swap(&a[min], &a[i]);
	}
}

//Questa funzione è quella richiamata n-1 volte da insertionSort e si occupa dei vari scambi di posizione
void insertSortedArray(int *a, int *n, int val) {
    int i; //Ci creiamo un variabile indice che inizializzeremo col valore di n
    for (i=*n;i>0 && val<a[i-1];i--) { //Scorriamo tutto l'array all'indietro finché o si arriva alla 1°posizione ed è quindi l'elemento più piccolo
        a[i]=a[i-1]; //o perché sono finiti gli elementi più grandi dell'elemento preso in considerazione
    }
    a[i]=val; //In ognuno di questi casi, finiti gli scambi di posizione verso destra, posizioniamo il valore che avevamo preso in considerazione
    (*n)++; //Incrementiamo n (che corrisponde ad i nell'altra funzione)
}

//Questa funzione fa da richiamo a quella di ordinamento e permette di ordinare tutti gli elementi dell'array grazie al ciclo al suo interno
void insertionSort(int *a, int n) {
	for (int i=1;i<n;) { //Passiamo per ogni elemento dell'array, partendo dal 2°elemento, perché il 1°elemento verrà spostato passo passo che vengono ordinati i valori (nel caso sia maggiore di essi)
		insertSortedArray(a,&i,a[i]); //Richiamiamo la funzione passandogli l'array, un valore passato per indirizzo che farà da indice e il valore da ordinare in quel momento
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

int main()
{
	int array[N];
	int n = 5;
	int val;
	inputArray(array, n);
	printf("N Operazioni: %d\n",adaptiveBubbleSort(array, n));
	outputArray(array, n);

	return 0;
}
