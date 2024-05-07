#include <stdio.h>
#define N 5

void swap(int *a, int *b) {
    int c=*a; //Ci creiamo una variabile c temporanea dove salviamo il valore di a
    *a=*b; //Mettiamo in a il valore di b
    *b=c; //Mettiamo in b il valore c (che corrisponde a quello di a)
} //SCAMBIO COMPLETATO

void inputArray(int *a,int n) {
    printf("Inserisci %d elementi:\n",n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
}

int minimo(int *a, int n) {
    int min=0; //Inizializziamo una variabile minimo a 0, essa corrisponderà al valore restituito e all'indirizzo del minimo dell'array dato
    for (int i=1;i<n;i++) { //Scorriamo tutto l'array partendo dall'elemento 1 (visto che il minimo di default è l'elemento 0) 
        if (a[min]>a[i]) min=i; //Se troviamo che l'elemento preso attualemente in esaminazione all'indirizzo i è minore di quello salvato all'indirizzo min, allora sostituiamo min con i
    }
    return min; //Alla fine restituiamo l'indirizzo del minimo trovato
}

void ordinaArray(int *a,int n) {
    int min; //Ci inizializziamo una variabile minimo
    for (int i=0;i<(n-1);i++) { //Scorriamo tutto l'array fino all'elemento n-1, perché quando arriveremo a quel punto avremo già ordinato tutto l'array e l'ultimo elemento sarà già il massimo
        min=minimo(a+i,N-i)+i; //Chiamiamo la funzione minimo (Spiegazione sotto)
        swap(&a[min],&a[i]); //Facciamo lo scambio tra il valore minimo e il valore preso attualmente preso in considerazione
    }
} //ARRRAY ORDINATO

void outputArray(int *a, int n) {
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int a[N];
    inputArray(a,N);
    ordinaArray(a,N);
    outputArray(a,N);
}