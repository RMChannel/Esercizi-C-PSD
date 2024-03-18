#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#define FALSE 0
#define TRUE 1

/*
input_array_str(...), data una stringa e un array e variabile puntatore pos, essa estrapola da una stringa l'array in esso contenuto.
Pos serve per spostare la posizione di calcolo dell'array dopo il 1° già scansionato (nel caso sia già stato fatta la scansione del 1°array),
questo lo controllo tramite l'if dove controllo se if è diverso da 0, se è uguale a 0 allora vuol dire che scansiono il 1°, altrimenti allora sposta
la linea di pos (tutti i caratteri scansionati prima) più 3 per saltare il carattere di separazione e gli spazi
*/
int input_array_str(int *arr, char *line, int *pos) {
    int i=0, n=0;
    if (*pos!=0) line+=*pos+3;
    while ((sscanf(line,"%d%n",&arr[i],&n))==1) {
        line+=n;
        *pos+=n;
        i++;
    }
    return i;
}

/*
Questa funzione server per ricavare un semplice dato intero, nel nostro caso viene utilizzato per ricavare il valore singolo dato dal file oracolo
*/
int getresult(char *line) {
    int n;
    sscanf(line,"%d",&n);
    return n;
}

/*
Restituisce la somma di tutti i valori di un array
*/
int sommaArray(int *arr, int imax) {
    int n=0;
    for (int i=0;i<imax;i++) n+=arr[i];
    return n;
}

/*
Questa funzione si occupa di sommare tutti i valori di due array e salvandoli nel primo,
l'if serve perché la funzione prevede che i due array possano avere due dimensioni diverse,
di conseguenza, visto che il for scorre i valori fino ad imax1, solo nel caso che imax1 (dimensione del 1° array)
sia minore di imax2 (dimensione del 2°array) allora sostituisce imax1 con imax2,
non c'è pericolo di andare fuori memoria perché gli array sono inizializzati tutti a 0 e di conseguenza anche se un array
non ha valori per suo limite, sono comunque inizializzati a 0 e di conseguenza facendo la somma di 0, restituisce i valori
dell'array con i valori inizializzati
*/
void somma2Array(int *arr1, int *arr2, int *imax1, int *imax2) {
    if (*imax1<*imax2) *imax1=*imax2;
    for (int i=0;(i<*imax1);i++) arr1[i]=arr1[i]+arr2[i];
}

/*
Questa funzione controlla che l'array dato e l'array dell'oracolo siano uguali, e che di conseguenza
il risultato sia corretto o meno
*/
int controlloOracleArray(int *arr, int *oracle, int imax) {
    for (int i=0;i<imax;i++) if (arr[i]!=oracle[i]) return 0;
    return 1;
}

/*
Questa funzione si occupa di fare la sommatoria dei prodotti tra i valori dell'array, ovvero la formula è questa: n=sommatoria(arr1[i]*arr2[i])
*/
int sumProd(int *arr1, int *arr2, int imax) {
    int n=0;
    for (int i=0;i<imax;i++) n+=(arr1[i]*arr2[i]);
    return n;
}

/*
Stampa l'intero array
*/
void outputArray(int *a, int n) {
	int i;
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

/*
Questa funzione, data una stringa di interi, restituisce il numero di elementi.
Esso viene calcolato tramite il conto degli spazi tra un numero e l'altro così da trovare il numero di elementi
*/
int conta_numeri(char *line) {
    int size=0;
    int controllo=TRUE; //variabile di controllo che ci permette di evitare di contare più spazi come più valori
    while (*line==' ') line++; //Eliminiamo tutti i possibili spazi prima di un numero
    for (;*line;line++) {
        if (*line==' ' && controllo) { //se è stato contato uno spazio, allora controllo deve diventare false, perché tutti gli altri possibili spazi non devono essere contati,
            size++;                    //e quando viene rielvato un numero ripristina controllo e cerca un nuovo sapzio da contare come elemento.
            controllo=FALSE;
        }
        else if (*line!=' ') controllo=TRUE;
    }
    return (size+1); //ritorna +1 perché l'ultimo elemento non ha spazi alla fine e di conseguenza aggiungo 1 per contarlo
}

int *input_array_dyn(int *size, char *line) {
    *size=conta_numeri(line);
    int i=0, n=0;
    int *arr=(int *) calloc(*size,sizeof(int));
    while ((sscanf(line,"%d%n",&arr[i],&n))==1) {
        line+=n;
        i++;
    }
    return arr;
}

void adaptiveBubbleSort(int *a, int n) { //adaptive bubble sort fatto in classe
	int ordinato=FALSE;
	for (int i=1;i<n && !ordinato;i++) {
		ordinato=TRUE;
		for (int j=0;j<(n-i);j++) {
			if (a[j]>a[j+1]) {
				swap(&a[j],&a[j+1]);
				ordinato=FALSE;
			}
		}
	}
}

/*
Crea un 3°array con n posizioni uguali alla somma del numero di elementi dei primi 2 array e
salva in codesto array tutti gli elementi del 1° array e del 2° messo assieme.
*/
int *concatena_vet(int *a, int *b, int n1, int n2, int *n3) {
    int *c=(int *) calloc((n1+n2),sizeof(int)); //Crea il 3°array
    int i;
    for (i=0;i<n1;i++) c[i]=a[i]; //Copia del 1°
    for (int i2=0;i2<n2;i2++,i++) c[i]=b[i2]; //Copia del 2°
    *n3=n1+n2;
    return c;
}