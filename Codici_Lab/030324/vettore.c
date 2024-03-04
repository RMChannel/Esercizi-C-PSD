#include <stdio.h>
#define MAXELEM 100

void input_array(int a[],int n) {
    int i=0;
    while (a[i]) i++;
    if (i==99) printf("Numero massimo di elementi raggiunto\n");
    else {
        for (int in=0;i<100 && in<n;i++,in++) {
            printf("Inserisci il %d°elemento: ",in+1);
            scanf("%d",&a[i]);
        }
    }
}

void output_array(int a[],int n) {
    int i=0;
    if (n==0) printf("Nessun elemento nell'array\n");
    else {
        do {
            printf("%d: %d\n",i+1,a[i]);
            i++;
        } while (i<n);
    }
    
}

void ricerca_array(int a[], int n, int max) {
    int i=0;
    for (;i<max;i++) {
        if (a[i]==n) {
            printf("Elemento trovato, si trova all'indirizzo %d\n",i+1);
            return;
        }
    }
    printf("L'elemento non è stato trovato\n");
}

int min_array(int *a, int n) {
    int min=0;
    for (int i=1;i<n;i++) {
        if (a[min]>a[i]) min=i;
    }
    return min;
}

void swap(int *a, int *b) {
    int c=*a;
    *a=*b;
    *b=c;
}

void ordinaArray(int *a,int n) {
    int min;
    for (int i=0;i<(n-1);i++) {
        min=min_array(a+i,n-i)+i;
        swap(&a[min],&a[i]);
    }
}

void delElemArray(int *a, int n, int elem) {
    int i=0;
    for (;i<n && a[i]!=elem;i++);
    if (i==n) printf("Elemento non trovato\n");
    else {
        a[i]=0;
        while ((i+1)<n) {
            a[i]=a[i+1];
            i++;
        }
        a[i+1]=0;
    }
}