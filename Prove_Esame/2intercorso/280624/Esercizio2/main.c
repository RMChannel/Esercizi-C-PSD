#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/*
Questa funzione si occupa della rimozione dell'elemento passato, prende in input lo stack su cui lavorare e l'item da eliminare.
*/
int findRmv(Stack stack, Item item) {
    Stack stackT=newStack(); //Mi creo uno stack temporaneo
    int i=0, iRmv=-1; //i rappresenta un contatore e iRmv rappresenta la posizione dell'elemento da rimuovere (se trovato)
    while(!isEmptyStack(stack)) { //Finché lo stack non è vuoto
        Item temp=top(stack); //Mi prendo l'elemento nello stack
        pop(stack); //Lo rimuovo
        if(cmpItem(item,temp)==0 && iRmv==-1) { //Se corrisponde all'elemento cercato e non è un altro elemento uguale
            iRmv=i; //Imposto iRmv su i (così da ricordarmi qual è l'elemento da rimuovere)
        }
        i++; //Incremento i
        push(stackT,temp); //Aggiungo l'elemento allo stack temporaneo
    }
    while(!isEmptyStack(stackT)) { //Finché lo stack temporaneo non è vuoto
        Item temp=top(stackT); //Mi prendo l'elemento nello stack
        pop(stackT); //Lo rimuovo
        i--; //Decremento i
        if(i!=iRmv) push(stack,temp); //Se la i corrisponde a quella di iRmv vuol dire che corrisponde a quella dell'elemento da rimuovere e che quindi non lo devo aggiungere, in caso contrario lo aggiungo
    }
    if(iRmv==-1) return 0; //Se iRmv è uguale a -1, di conseguenza non abbiamo fatto nessuna operazione sulla rimozione, allora ritorno 0 perché viol dire che non abbiamo trovato l'elemento
    else return 1; //Al contrario restituisce 1, perché vuol dire che abbiamo trovato l'elemento e l'abbiamo rimosso
}

//Questa funzione ha lo scopo di stampare e di richiamare la funzione di ricerca, infatti prende in input lo stack su cui lavorare e l'item da eliminare
void printRmv(Stack stack, Item item) {
    printf("Stack originale: ");
    printStack(stack); //Stampo lo stack prima della rimozione
    printf("\nElemento da rimuovere: ");
    outputItem(item); //Stampo l'elemento dai rimuovere
    if(findRmv(stack,item)) printf("\nElemento rimosso\n"); //Richiamo la funzione e se restituisce 1 allora viol dire che è stato trovato l'elemento da rimuovere e che è stato rimosso
    else printf("\nElemento non presente\n"); //Altrimenti stampa che l'elemento non era presente
    printf("Stack dopo rim.: "); //Stampo lo stack dopo la rimozione
    printStack(stack);
    printf("\n\n");
}

int main() {
    char *ciao=malloc(sizeof(char)*10);
    char *bella=malloc(sizeof(char)*10);
    char *gente=malloc(sizeof(char)*10); //Creo gli elementi di test
    char *va=malloc(sizeof(char)*10);
    strcpy(ciao,"ciao");
    strcpy(bella,"bella");
    strcpy(gente,"gente");
    strcpy(va,"va");
    Stack stack=newStack();
    Stack stackOnlyOne=newStack(); //Creo gli stack da testare
    Stack stackEmpty=newStack();
    Stack stack2=newStack();
    Stack stackRandom=newStack();
    push(stackOnlyOne,ciao);
    push(stack,ciao);
    push(stack,bella);
    push(stack,gente); //Aggiungo gli elementi nell'ordine di inserimento descritto
    push(stack,bella);
    push(stack,va);
    push(stack2,bella);
    push(stack2,gente);
    push(stack2,bella);
    push(stack2,va);
    for(int i=0;i<9;i++) {
        push(stackRandom,randomItem()); //Aggiungo gli elementi randomici allo stack random
    }
    printRmv(stackEmpty,"ciao");
    printRmv(stackOnlyOne,"ciao"); //Richiamo la stampa del rmvimo per ogni stack richiesto
    printRmv(stack,"ciao");
    printRmv(stack2,"bella");
    printRmv(stackRandom,randomItem());
}