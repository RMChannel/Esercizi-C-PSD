#include <stdlib.h>
#include <stdio.h>
#include "auto.h"
#include "catalogo.h"

struct catalogo{ //Mi creo la struttura catalogo con solo la lista
    Car catalogo[100];
    int n;
};

Catalogo newCatalogo() { //Questa funzione si occupa di creare un catalogo nella memoria
    Catalogo catalogo=malloc(sizeof(struct catalogo)); //Alloco la memoria necessaria
    catalogo->n=0;
    return catalogo; //Restituisco il catalogo creato
}

void addCatalogo(Car car, Catalogo catalogo) { //Questa funzione si occupa di aggiungere un auto al catalogo, prende in input l'auto da aggiungere e il catalogo 
    if(catalogo->n==100) {
        printf("Memoria terminata\n");
        return;
    }
    else {
        catalogo->catalogo[catalogo->n]=car;
        catalogo->n++;
    }
}

void sellCar(Car car, Catalogo catalogo) { //Questa funzione si occupa di rimuovere un auto al catalogo, prende in input l'auto da rimuovere e il catalogo 
    for(int i=0;i<catalogo->n;i++) {
        if(car==catalogo->catalogo[i]) {
            for(;i<catalogo->n;i++) catalogo->catalogo[i]=catalogo->catalogo[i+1];
            catalogo->n--;
            return;
        }
    }
    printf("Auto non trovata\n");
}

void printCatalogo(Catalogo catalogo) { //Questa funzione si occupa della stampa del catalogo, prende in input solo il catalogo da stampare
    for(int i=0;i<catalogo->n;i++) outputItem(catalogo->catalogo[i]);
}

Car searchForMarchio(Catalogo catalogo, char *marchio) {
    Car temp=newcar(marchio,"",0,0);
    for(int i=0;i<catalogo->n;i++) {
        if(confrontoMarca(catalogo->catalogo[i],temp)==0) return catalogo->catalogo[i];
    }
    return NULL;
}

Car searchForModello(Catalogo catalogo, char *modello) {
    Car temp=newcar("",modello,0,0);
    for(int i=0;i<catalogo->n;i++) {
        if(confrontoModello(catalogo->catalogo[i],temp)==0) return catalogo->catalogo[i];
    }
    return NULL;
}