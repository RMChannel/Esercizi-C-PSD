#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piatto.h"

struct piatto{
    char *nome;
    float prezzo;
    char *ingredienti;
};

Piatto newPiatto(char *nome, float prezzo, char *ingredienti) {
    Piatto piatto=malloc(sizeof(struct piatto));
    piatto->prezzo=prezzo;
    char *n=malloc(sizeof(char)*200);
    strcpy(n,nome);
    piatto->nome=n;
    char *i=malloc(sizeof(char)*200);
    strcpy(i,ingredienti);
    piatto->ingredienti=i;
    return piatto;
}

void editPiatto(Piatto piatto, char *nome, float prezzo, char *ingredienti) {
    if (*nome) {
        char *n=malloc(sizeof(nome));
        strcpy(n,nome);
        piatto->nome=n;
    }
    if (*ingredienti) {
        char *n=malloc(sizeof(ingredienti));
        strcpy(n,ingredienti);
        piatto->ingredienti=n;
    }
    if (prezzo!=0) {
        piatto->prezzo=prezzo; 
    }
}

int search(Piatto p1, Piatto p2, int n) {
    if(n==1) return (p1->prezzo)>(p2->prezzo);
    else return strcmp(p1->nome,p2->nome)>0;
}

void outputPiatto(Piatto p) {
    printf("Nome: %s Ingredienti: %s Prezzo: %.2f\n",p->nome,p->ingredienti,p->prezzo);
}