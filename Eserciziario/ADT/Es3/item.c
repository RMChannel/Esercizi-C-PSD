#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct item{
    char *nome;
    int quantita;
    float prezzo;
};

Item newItem(char *name, int q, float p) {
    Item item=malloc(sizeof(struct item));
    item->quantita=q;
    item->prezzo=p;
    char *n=malloc(sizeof(name));
    strcpy(n,name);
    item->nome=n;
    return item;
}

void outputItem(Item item) {
    printf("Nome: %s\nQuantita': %d\nPrezzo: %.2f\n",item->nome,item->quantita,item->prezzo);
}

float returnPrice(Item item) {
    return (item->prezzo)*(item->quantita);
}