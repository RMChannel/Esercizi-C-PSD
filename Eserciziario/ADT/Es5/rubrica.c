#include <stdio.h>
#include <stdlib.h>
#include "contatto.h"
#include "rubrica.h"

struct rubrica{
    Contatto rubrica[100];
    int size;
};

Rubrica newRubrica() {
    Rubrica rubrica=malloc(sizeof(struct rubrica));
    rubrica->size=0;
    return rubrica;
}

void addRubrica(Rubrica r, Contatto c) {
    int i;
    for(i=0;i<r->size;i++);
    if (i>=100) return;
    r->rubrica[i]=c;
    r->size++;
}

void printRubrica(Rubrica r) {
    for(int i=0;i<(r->size);i++) outputContatto(r->rubrica[i]);
}