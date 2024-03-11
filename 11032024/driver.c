

#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"

#define N 50

int main(int argc, char *argv[]){

    FILE *fp_input, *fp_oracle, *fp_output;

//controllo se i file esistono e si possono aprire
    if((fp_input=fopen(argv[1], "r"))==NULL){//r per aprirlo in modalità read (lettura)
         fprintf(stderr, "Errore aperura file input.txt\n");
        exit(EXIT_FAILURE);
    }

    if((fp_oracle=fopen(argv[2], "r"))==NULL){//r per aprirlo in modalità read (lettura)
        fprintf(stderr, "Errore aperura file oracolo.txt\n");
        exit(EXIT_FAILURE);
    }

    if((fp_output=fopen(argv[3], "w"))==NULL){//w per aprirlo in modalità write (scrittura)
        fprintf(stderr, "Errore aperura file output.txt\n");
        exit(EXIT_FAILURE);
    }


//dichiarazioni delle variabili
    char line[N];
    int n_input[N]={0};//array input che andremo ad utilizzare 
    int n_oracle = 0;//valore che prendiamo dal file oracle per fare il controllo/confroto
    int imax;//il numero limite degli elementi dell'array (limite perchè è il numero di caratteri inseriti dal file)
    int pos;//posizione della stringa dopo un primo utilizzo della funzione(pos serve a spostarsi sulla stringa)
    int result; //somma totale dell'array restituita dalla funzione

    for(int i=1; fgets(line, N, fp_input) != NULL; i++){//la i ha solo un valore grafico (ovvero conta le righe del file)

        imax=input_array_str(n_input, line, &pos);
        result=sum_array(n_input, imax);

        //ci prendiamo la linea di oracle e la salviamo in line
        fgets(line, N, fp_oracle);
        n_oracle=getresult(line);

        //faccio il confronto e stampo il risultato
        fprintf(fp_output, "Test case %d: %d\n", i, (result==n_oracle));//stampa nel file output direttamente il confronto 
        //(result==n_oracle) se sono uguali darà 1 altrimenti 0
    
    }   


//chiusura dei file
    fclose(fp_input);
    fclose(fp_output);
    fclose(fp_oracle);

}






