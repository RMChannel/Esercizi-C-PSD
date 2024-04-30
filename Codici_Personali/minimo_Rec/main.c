#include <stdio.h>

int minimo(int *a, int actualMin, int n, int i) {
    if (i==n) return actualMin;
    else if (*a<actualMin) actualMin=*a;
    return minimo(a+1,actualMin,n,i+1);
}

int minimoRic(int *a, int n) {
    return minimo(a+1,*a,n,1);
}


int minimo2(int *a, int actualMin, int n, int i, int iMin) {
    if (i==n) return iMin;
    else if (*a<actualMin) {
        actualMin=*a;
        iMin=i;
    }
    return minimo2(a+1,actualMin,n,i+1,iMin);
}

int minimoRic2(int *a, int n) {
    return minimo2(a+1,*a,n,1,0);
}

int main(int argc, char *argv[]) {
    int a[]={5,16,23,3,47,8};
    int n=6;
    printf("%d\n",minimoRic2(a,n));
}