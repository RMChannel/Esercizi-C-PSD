#include <stdio.h>
#define N 5

void swap(int *a, int *b) {
    int c=*a;
    *a=*b;
    *b=c;
}

void inputArray(int *a,int n) {
    printf("Inserisci %d elementi:\n",n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
}

int minimo(int *a, int n) {
    int min=0;
    for (int i=1;i<n;i++) {
        if (a[min]>a[i]) min=i;
    }
    return min;
}

void ordinaArray(int *a,int n) {
    int min;
    for (int i=0;i<(n-1);i++) {
        min=minimo(a+i,N-i)+i;
        swap(&a[min],&a[i]);
    }
}

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