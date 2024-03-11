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
    /*
    dichiaro le variabili, qui mi servono 3 array, ovvero i 2 di input e quello di controllo dell'oracolo,
    inoltre mi serve pos
    */
    char line[N]="";
    int n_input1[N]={0};
    int n_input2[N]={0};
    int n_oracle[N]={0};
    int imax1, imax2, pos;
    for (int i=1;fgets(line,N,fp_input)!=NULL;i++) {
        pos=0;
        imax1=input_array_str(n_input1,line,&pos); //mi salvo i due array con le loro dimensioni
        imax2=input_array_str(n_input2,line,&pos);
        somma2Array(n_input1,n_input2,&imax1,&imax2); //mi calcolo la somma dei due array e la salvo nel 1°
        pos=0;
        fgets(line,N,fp_oracle);
        input_array_str(n_oracle,line,&pos); //mi salvo l'array di oracle
        fprintf(fp_output,"Test %d: %d\n",i,controlloOracleArray(n_input1,n_oracle,imax1)); //stampo il controllo nel file di output
    }
    fclose(fp_input);
    fclose(fp_oracle);
    fclose(fp_output);
}