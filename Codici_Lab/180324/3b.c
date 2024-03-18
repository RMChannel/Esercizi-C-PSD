#include <stdio.h>
#include "vettore.h"

int main(int argc, char *argv[]) {
    int n1, n2, n3;
    char line[100]="";
    int *a, *b, *c;
    printf("Inserisci il 1° vettore: ");
    scanf("%[^\n]",line);
    a=input_array_dyn(&n1, line); //Mi prendo il 1°array
    while (getchar()!='\n');
    printf("Inserisci il 2° vettore: ");
    scanf("%[^\n]",line);
    b=input_array_dyn(&n2, line); //Mi prendo il 2°array
    c=concatena_vet(a,b,n1,n2,&n3); //Concateno i 2 array
    outputArray(c,n3); //Stampo l'array
    return 0;
}