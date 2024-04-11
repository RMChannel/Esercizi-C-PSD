#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Fibo(int n) {
    int f=1, f1=1, f2=1, i;
    for (i=2;i<=n;i++) {
        f=f1+f2;
        f2=f1;
        f1=f;
    }
    return f;
}

int FiboRic(int n) {
    if (n<=1) return 1;
    else return FiboRic(n-1)+FiboRic(n-2);
}

int main(int argc, char *argv[]) {
    if (argc!=2) {
        fprintf(stderr,"Numero di parametri errato\n");
        exit(EXIT_FAILURE);
    }
    int n=atoi(argv[1]);
    printf("Fib di %d uguale a: %d\n",n,FiboRic(n));
    return 0;
}