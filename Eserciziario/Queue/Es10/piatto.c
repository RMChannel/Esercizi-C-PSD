#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piatto.h"

struct ordine{
    char *piatto;
    int nTavolo;
};

Ordine newPiatto(char *p, int n) {
    Ordine ordine=malloc(sizeof(struct ordine));
    ordine->nTavolo=n;
    char *s=malloc(sizeof(char)*200);
    strcpy(s,p);
    ordine->piatto=s;
}

void outputPiatto(Ordine p) {
    printf("Piatto: %s \t al tavolo: %d\n",p->piatto,p->nTavolo);
}