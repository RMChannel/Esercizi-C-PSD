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
    //dichiaro le variabili
    char line[N]="";
    int n_input[N]={0};
    int n_oracle=0, imax, result, pos;
    for (int i=1;fgets(line,N,fp_input)!=NULL;i++) {
        pos=0;
        imax=input_array_str(n_input,line,&pos); //mi prendo l'array dalla stringa e mi salvo in imax la sua dimensione
        result=sommaArray(n_input,imax); //calcolo la somma di tutti gli elementi dell'array
        fgets(line,N,fp_oracle);
        n_oracle=getresult(line); //mi prendo il risultato previsto dal file oracolo
        fprintf(fp_output,"Test %d: %d\n",i,(result==n_oracle)); //stampo il controllo nel file output
    }
    fclose(fp_input);
    fclose(fp_oracle);
    fclose(fp_output);
}