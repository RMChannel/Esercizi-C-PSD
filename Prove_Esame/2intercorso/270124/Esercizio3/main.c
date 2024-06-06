#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


/*
Questa funzione si occupa della copia di uno stack in un altro, cancellando quello originale.
Prende in input due stack, quello originale e quello su cui copiare.
*/
void copyStack(Stack stack, Stack stackTemp) {
    if(!isEmptyStack(stack)) { //Se lo stack originale non è vuoto
        Item temp=top(stack); //Alora mi prendo il suo elemento in top
        pop(stack); //Lo rimuovo
        copyStack(stack,stackTemp); //Chiamata ricorsiva
        push(stackTemp,temp); //E alla fine rimetto tutto dentro allo stack
    }
}


/*
Questa funzione si occupa di fare il reverse dello stack, senza inserire valori minori o uguali al parametro.
Essa prende in input solo lo stack e il parametro.
*/
void reverseStack(Stack stack, char *param) {
    Stack stackTemp=newStack(); //Mi creo uno stack temporaneo
    copyStack(stack,stackTemp); //Copio lo stack originale dentro allo stack temporaneo (nel frattempo cancellando quello originale)
    while(!isEmptyStack(stackTemp)) { //Finché non svuoto lo stack temporaneo
        Item temp=top(stackTemp); //Prendo ogni elemento di quello temporaneo
        pop(stackTemp); //Lo rimuovo
        if(cmpItem(temp,param)>0) push(stack,temp); //Se l'item è maggiore del parametro, allora viene rimesso nello stack
    }
    free(stackTemp); //Libero la memoria dello stack temporaneo, visto che esso non è più necessario
}


/*
Questa funzione è quella che si occupa di stampare lo stack, prima e dopo il reverse.
Prende come parametri solo lo stack e il parametro.
*/
void printAndReverse(Stack stack, char *param) {
    printf("Parametro: %s\nStack prima: ",param); //Stampo il parametro
    printStack(stack); //Stampo lo stack prima del reverse
    reverseStack(stack,param); //Richiamo la funzione di reverse
    printf("\nStack dopo: ");
    printStack(stack); //Stampo lo stack dopo la funzione
    printf("\n\n");
}

int main() {
    char *ciao=malloc(sizeof(char)*10);
    char *bella=malloc(sizeof(char)*10);
    char *gente=malloc(sizeof(char)*10);
    char *come=malloc(sizeof(char)*10); //Mi creo gli item di test
    char *va=malloc(sizeof(char)*10);
    strcpy(ciao,"ciao");
    strcpy(bella,"bella");
    strcpy(gente,"gente");
    strcpy(come,"come");
    strcpy(va,"va");
    Stack stack1=newStack();
    Stack stack2=newStack(); //Creo i 5 stack di test richiesti
    Stack stack3=newStack();
    Stack stack4=newStack();
    Stack stack5=newStack();
    push(stack2,ciao); //Inserisco gli elmenti adeguati
    
    push(stack3,ciao);
    push(stack3,bella);
    push(stack3,gente);
    push(stack3,come);
    push(stack3,va);

    push(stack4,ciao);
    push(stack4,bella);
    push(stack4,gente);
    push(stack4,come);
    push(stack4,va);

    for(int i=0;i<7;i++) {
        push(stack5,randomItem()); //Inserisco gli elementi randomici
    }

    printAndReverse(stack1,"ciao");
    printAndReverse(stack2,"ciao");
    printAndReverse(stack3,"ciao"); //Richiamo alle funzioni con ogni stack e i parametri richiesti
    printAndReverse(stack4,"dado");
    printAndReverse(stack5,randomItem());
}