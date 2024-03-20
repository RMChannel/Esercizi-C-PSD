#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct studente{
    char nome[20];
    int matricola;
};
typedef struct studente *Studente;

Item inputItem() {
    Studente pStudente=malloc(sizeof(struct studente));
    scanf("%d",&pStudente->matricola);
    scanf("%s",pStudente->nome);
    return pStudente;
}

void outputItem(Item item) {
    Studente pStudente=item;
    printf("nome= %s\nmatricola= %d\n",pStudente->nome,pStudente->matricola);
}

int cmpItem(Item item1, Item item2) {
    Studente pStudente1=item1;
    Studente pStudente2=item2;
    int mat1=pStudente1->matricola;
    int mat2=pStudente2->matricola;
    return (pStudente1->matricola)-(pStudente2->matricola);
}