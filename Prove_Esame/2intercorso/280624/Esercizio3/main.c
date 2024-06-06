#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

/*
Questa funzione si occupa di trovare il minimo della coda e di metterlo in testa, prendein input solo la coda su cui lavorare
*/
void minQueue(Queue queue) {
    if(isEmptyQueue(queue)) return; //Se la coda è vuota, ritorno direttamente
    Queue temp=newQueue(); //Creo una coda temporanea
    Item min=dequeue(queue); //Imposto il minimo al 1°elemento della coda
    enqueue(temp,min);
    int i=0, iMin=0; //Due variabili contatori, una di posizione standard e l'altra quella del minmo
    while(!isEmptyQueue(queue)) { //Finché la coda originale non è vuota
        Item tempItem=dequeue(queue); //Mi salvo l'elemento
        enqueue(temp,tempItem); //Aggiungo alla coda temporanea
        i++;
        if(cmpItem(min,tempItem)>0) { //Controllo se esso è minore dell'item attualmente preso in esame
            min=tempItem; //Se lo è, allora lo salvo
            iMin=i; //E salvo anche il suo indice
        }
    }
    enqueue(queue,min); //Aggiungo il minimo alla coda originale (visto che ora dev'essere la testa)
    i=0; //Reimposto
    while(!isEmptyQueue(temp)) { //Finché la coda temporanea non è vuota
        Item tempItem=dequeue(temp); //Prendo l'elemento dalla coda temp
        if(cmpItem(min,tempItem)!=0 || i!=iMin) enqueue(queue,tempItem); //Controllo che non sia il minimo o che non si trovi alla sua posizione
        i++; //Incremento i
    }
}

//Questa funzione ha il solo scopo di stampa, prende in input solo la coda su cui lavorare
void printMin(Queue queue) {
    printf("Coda originale: ");
    printQueue(queue); //Stampo la coda prima della funzione di minimo
    printf("\nCoda modificata: ");
    minQueue(queue); //Richiamo alla funzione
    printQueue(queue); //Stampo la coda dopo la funzione diminimo
    printf("\n\n");
}

int main() {
    char *ciao=malloc(sizeof(char)*10);
    char *bella=malloc(sizeof(char)*10);
    char *gente=malloc(sizeof(char)*10);
    char *casa=malloc(sizeof(char)*10); //Creo gli item di test
    char *va=malloc(sizeof(char)*10);
    strcpy(ciao,"ciao");
    strcpy(bella,"bella");
    strcpy(gente,"gente");
    strcpy(casa,"casa");
    strcpy(va,"va");
    Queue queue1=newQueue();
    Queue queue2=newQueue();
    Queue queue3=newQueue(); //Creo le 5 code richieste
    Queue queue4=newQueue();
    Queue queue5=newQueue();
    enqueue(queue2,ciao);
    enqueue(queue3,ciao);
    enqueue(queue3,bella);
    enqueue(queue3,casa);
    enqueue(queue4,ciao); //Aggiungo i loro elementi
    enqueue(queue4,bella);
    enqueue(queue4,gente);
    enqueue(queue4,bella);
    enqueue(queue4,va);
    for(int i=0;i<5;i++) {
        enqueue(queue5,randomItem()); //Aggiungo gli elementi randomici alla coda random
    }
    printMin(queue1);
    printMin(queue2);
    printMin(queue3); //Richiamo la funzione di stampa per ogni coda richiesta
    printMin(queue4);
    printMin(queue5);
}