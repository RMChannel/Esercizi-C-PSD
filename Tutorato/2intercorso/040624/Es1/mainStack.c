#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
Questa funzione si occupa di memorizzare i caratteri della stringa nello stack.
Essa prende in input lo stack e il puntatore alla stringa.
La complessità di questa funzione è di O(n)
*/
void getChar(Stack stack, char *s) {
    if(*s) { //Se la stringa non è finita
        char *c=malloc(sizeof(char)); //Crea il carattere in memoria
        (*c)=(*s); //Prendi il valore del carattere della stringa
        push(stack,c); //Push nello stack
        getChar(stack,s+1); //Richiamata ricorsiva col puntatore alla stringa aumentato di 1
    }
}


/*
Questa funzione si occupa della stampa finale della stringa in modo inverso e del conteggio dei caratteri.
Prende in input lo stack e una variabile n (che rappresenta il conto dei caratteri).
La complessità di questa funzione è di O(n)
*/
void printChar(Stack stack, int n) {
    if(!isEmptyStack(stack)) { //Se lo stack non è vuoto
        char *c=top(stack); //Allora mi prendo l'elemento più in alto
        pop(stack); //Lo rimuovo 
        printf("%c",*c); //Stampo
        printChar(stack,n+1); //Chiamata ricorsiva col numero di caratteri aumentato di 1
    }
    else printf(" %d\n",n); //Quando lo stack è vuoto faccio la stampa del numero di caratteri
}

void printReverse(char *s) { //Questa funzione si occupa solamente di creare lo Stack di appoggio e di richiamare le due funzioni
    Stack stack=newStack(); //Creo lo stack
    getChar(stack, s); //Richiamo la funzione di memorizzazione
    printChar(stack,0); //Richiamo la funzione di stampa
}

int main() {
    char s[200]; //Dichiaro la stringa dove andrò a salvare la parola su cui lavorare
    printf("Inserisci una parola: ");
    scanf("%s",s); //Faccio inserire la parola all'utente
    printReverse(s); //Richiamo alla funzione
}