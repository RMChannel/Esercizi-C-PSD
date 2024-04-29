#include <stdio.h>
#include "item.h"

void printArray(Item a[], int n) {
    for (int i=0;i<n;i++) outputItem(a[i]);
    printf("\n");
}

int minimo(Item a[],int n) {
    int min=0;
    for (int i=1;i<n;i++) {
        if (cmpItem(a[min],a[i])) min=i;
    }
    return min;
}

/*
La complessità asintotica di questa funzione di ordinamento è di O(n²) perché
ogni volta che viene richiamata la funzione, viene trovato il minimo di dell'array di n-start elementi,
inoltre, l'ordinamento esegue il calcolo del minimo e lo swap n volte, di conseguenza c'è l'esecuzione dell'ordinamento n volte
e l'esecuzione del calcolo del minimo per altre n volte, di conseguenze n².
*/

void ordinaArray(Item a[], int n, int start) {
    if (start==(n-1)) return;
    else {
        int min=minimo(a+start,n-start)+start;
        swapItem(a[min],a[start]);
        return ordinaArray(a,n,start+1);
    }
}

void selectionSortRic(Item a[], int n) {
    ordinaArray(a,n,0);
}