
#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"

#define N 50

int main(int argc, char *argv[]){

    FILE *fp_input, *fp_oracle, *fp_output;

//controllo se i file esistono e si possono aprire
    if((fp_input=fopen(argv[1], "r"))==NULL){
         fprintf(stderr, "Errore aperura file input.txt\n");
        exit(EXIT_FAILURE);
    }

    if((fp_oracle=fopen(argv[2], "r"))==NULL){
        fprintf(stderr, "Errore aperura file oracolo.txt\n");
        exit(EXIT_FAILURE);
    }

    if((fp_output=fopen(argv[3], "w"))==NULL){
        fprintf(stderr, "Errore aperura file output.txt\n");
        exit(EXIT_FAILURE);
    }
//dichiarazioni delle variabili
    char line[N];
    int n_input[N]={0}; //primo array
    int n_input2[N]={0}; //secondo array
    int n_oracle[N]={0}; //array di controllo/conferma
    int imax;//lunghezza limite primo array
    int imax2; //lunghezza limite secondo array
    int pos;//ci serve per gli esercizi dopo
    int controllo; //valore da controllare 

    for(int i=1; fgets(line, N, fp_input) != NULL; i++){//la fgets si prende la prima riga di input_file.txt
    //la i ha solo un valore grafico (ovvero conta le righe del file)

        imax=input_array_str(n_input, line, &pos);//dimensione limite dell'array 1
        fgets(line, N, fp_input);//con la fgets passa dalla prima alla seconda linea (prende in input la seconda riga da sommare da input_file.txt)
        imax2=input_array_str(n_input2, line, &pos);//dimensione limite dell'array 2
        fgets(line, N, fp_oracle);//prende la linea di oracle che andrà confrontata con la nuova linea risultante dalla somma delle 2 linee di input_file.txt
        input_array_str(n_oracle, line, &pos);//converto la stringa di oracolo in array oracolo
    
        sum_2array(n_input, n_input2, &imax, &imax2 );
        //chiamo la funzione di controllo e stampo il risultato
        fprintf(fp_output, "test %d: %d\n", i, controlloOracleArray(n_input, n_oracle, imax));
    }


//chiusura dei file
    fclose(fp_input);
    fclose(fp_output);
    fclose(fp_oracle);
}