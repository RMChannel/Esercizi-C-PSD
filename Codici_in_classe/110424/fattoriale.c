#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int fact(int n) {
    int i, fat=1;
    for (i=n;i>1;i--) {
        fat*=i;
    }
    return fat;
}

int factRic(int n) {
    if (n<=1) return 1;
    else return n*factRic(n-1);
}

int main(int argc, char *argv[]) {
    if (argc!=2) {
        fprintf(stderr,"Numero di parametri errato\n");
        exit(EXIT_FAILURE);
    }
    int n=atoi(argv[1]);
    printf("Fattoriale di %d uguale a: %d\n",n,factRic(n));
    return 0;
}