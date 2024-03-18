#include <stdio.h>
#include "vettore.h"

int main(int argc, char *argv[]) {
    int n;
    char line[100]="";
    int *a;
    printf("Inserisci il vettore: ");
    scanf("%[^\n]",line); //Mi salvo l'array
    a=input_array_dyn(&n, line);
    adaptiveBubbleSort(a, n); //Ordino l'array
    outputArray(a, n); //Lo stampo
    return 0;
}