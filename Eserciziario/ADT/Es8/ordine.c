#include <stdio.h>
#include <stdlib.h>
#include "ordine.h"

struct ordine{
    int ID;
    int nProd;
    float prezzo;
    int giorno;
    int mese;
    int anno;
};

struct ordini{
    Ordine Orders[100];
    int size;
};

Ordini newOrdini() {
    Ordini ordini=malloc(sizeof(struct ordini));
    ordini->size=0;
    return ordini;
}

Ordine newOrdine(int ID, int prod, float prezzo, int giorno, int mese, int anno) {
    Ordine ordine=malloc(sizeof(struct ordine));
    ordine->ID=ID;
    ordine->nProd=prod;
    ordine->prezzo=prezzo;
    ordine->giorno=giorno;
    ordine->mese=mese;
    ordine->anno=anno;
    return ordine;
}

void addOrdine(Ordini orders, Ordine ord) {
    if(orders->size==100) return;
    orders->Orders[orders->size]=ord;
    orders->size++;
}

void removeOrdine(Ordini orders, Ordine ord) {
    for(int i=0;i<orders->size;i++) {
        if(ord==orders->Orders[i]) {
            for(;i<orders->size;i++) orders->Orders[i]=orders->Orders[i+1];
            orders->size--;
            return;
        }
    }
    printf("Ordine non trovato\n");
}

float total(Ordini orders) {
    float totale=0;
    for(int i=0;i<orders->size;i++) totale+=orders->Orders[i]->prezzo;
    return totale;
}

int calcoladata(int g, int m, int a) {
    return g+(m*30)+(a*365);
}

void showOrders(Ordini orders) {
    int done[100]={0};
    for(int i2=0;i2<orders->size;i2++) {
        int max=0;
        int maxI=0;
        for(int i=0;i<orders->size;i++) {
            Ordine ord=orders->Orders[i];
            int temp=calcoladata(ord->giorno,ord->mese,ord->anno);
            if(temp>max && !done[i]) {
                maxI=i;
                max=temp;
            }
        }
        done[maxI]=1;
        Ordine ord=orders->Orders[maxI];
        printf("ID: %d Numero prodotti: %d Totale: %.2f Data:%d/%d/%d\n",ord->ID,ord->nProd,ord->prezzo,ord->giorno,ord->mese,ord->anno);
    }
}