#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

/*
Questa funzione è colei che si occupa della stampa inversa e di calcolare il numero di caratteri della stringa.
Prende in input: la stringa su cui lavorare, un intero passato per indirizzo (dove memorizzerò il numero di caratteri) e lo stack di appoggio.
Essa restituirà il numero di caratteri della stringa passata
*/
void reversePrintAndCount(char *s, int *n,Stack stack) {
    if(!(*s)) { //PASSO BASE, ovvero nel caso in cui ho raggiunto il carattere di fine stringa
        while(!isEmptyStack(stack)) { //Svuoto passo passo lo stack finché non è vuoto
            char *c=top(stack); //Mi prendo l'elemento top
            printf("%c",*c); //Lo stampo
            pop(stack); //E lo elimino dallo stack
        }
        return; //Termino la funzione
    }
    else { //PASSO RICORSIVO
        char *c=malloc(sizeof(char)); //Mi creo il carattere che andrò a mettere nello stack
        (*c)=(*s); //Ci salvo il carattere della stringa
        Item item=c; //Lo passo ad un item(visto che la funzione push richiede un item)
        push(stack,c); //Salvo nello stack il carattere
        if(((*c)>='a' && (*c)<='z') || ((*c)>='A' && (*c)<='Z') || ((*c)>='0' && (*c)<='9')) (*n)++; //Controllo che sai un carattere alfanumerico e nel caso lo conto
        reversePrintAndCount(s+1,n,stack); //Richiamo la funzione in modo ricorsivo
    }
}

int CallReversePrintAndCount(char *s) { //Funzione di richiamo che prende in input solamente la stringa su cui lavorare
    int n=0; //Mi dichiaro una variabile intera dove andrò a mettere il numero di caratteri alfanumerici
    Stack stack=newStack(); //Mi creo uno stack di appoggio
    reversePrintAndCount(s,&n,stack); //Richiamo la funzione
    free(stack); //Cancello lo stack, visto che non è oiù necessario
    return n;
}

int main() {
    FILE *fp;
    if(!(fp=fopen("input.txt","r"))) { //Carico il file e controllo che esiste
        fprintf(stderr,"File non trovato\n"); //Nel caso non esista, stampo l'errore
        exit(EXIT_FAILURE);
    }
    char line[100]; //Stringa di appoggio dove andrò a mettere la stringa da file
    while(fgets(line,sizeof(line),fp)) { //While che mi da in line, ad ogni ciclo, una riga del file
        printf(" %d",CallReversePrintAndCount(line)); //Richiamo alla funzione e stampa del numero di caratteri
        
    }
    return 0;
}
