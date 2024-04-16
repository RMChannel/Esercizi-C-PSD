#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "auto.h"
#define N 100

Item inputItem() {
    char *modello=malloc(sizeof(char)*N);
    char *targa=malloc(sizeof(char)*N);
    int annoI, annoP;
    printf("Inserisci il modello: ");
    scanf("%[^\n]",modello);
    printf("Inserisci la targa: ");
    scanf("%s",targa);
    printf("Inserisci l'anno di immatricolazione: ");
    scanf("%d",&annoI);
    printf("Inserisci l'anno di produzione: ");
    scanf("%d",&annoP);
    return initAuto(targa,annoI,annoP,modello);
}

void outputItem(Item car) {
    printf("Modello: %s\nTarga: %s\nAnno di immatricolazione: %d\nAnno di produzione: %d\n",modello(car),targa(car),annoI(car),annoP(car));
}

int cmpItem(Item car1, Item car2) {
    return (annoP(car1)-annoP(car2));
}