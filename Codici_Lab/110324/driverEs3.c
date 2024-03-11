#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"
#define N 100

int main(int argc, char *argv[]) {
    //Apertura e controllo dell'esistenza dei file
    FILE *fp_input, *fp_oracle, *fp_output;
    if ((fp_input=fopen(argv[1],"r"))==NULL) {
        printf("File input non trovato\n");
        exit(EXIT_FAILURE);
    }
    if ((fp_oracle=fopen(argv[2],"r"))==NULL) {
        printf("File oracolo non trovato\n");
        exit(EXIT_FAILURE);
    }
    if ((fp_output=fopen(argv[3],"w"))==NULL) {
        printf("File output non trovato\n");
        exit(EXIT_FAILURE);
    }
    //dichiaro le variabili, in questo caso mi servono i due array di input, perché l'oracolo mi da un singolo valore di controllo
    char line[N]="";
    int n_input1[N]={0};
    int n_input2[N]={0};
    int n_oracle, imax, pos, result;
    for (int i=1;fgets(line,N,fp_input)!=NULL;i++) {
        pos=0;
        imax=input_array_str(n_input1,line,&pos); //mi salvo i due array
        input_array_str(n_input2,line,&pos);
        result=sumProd(n_input1, n_input2, imax); //calcolo la sommatoria e la salvo in result
        pos=0;
        fgets(line,N,fp_oracle);
        n_oracle=getresult(line); //salvo il valore di controllo
        fprintf(fp_output,"Test %d: %d\n",i, (n_oracle==result)); //stampo il controllo nel file di output
    }
}