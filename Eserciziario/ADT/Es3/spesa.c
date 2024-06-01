#include <stdio.h>
#include <stdlib.h>
#include "spesa.h"
#include "item.h"

struct spesa{
    Item spesa[100];
    int elementi;
};

Spesa newSpesa() {
    Spesa spesa=malloc(sizeof(struct spesa));
    spesa->elementi=0;
    return spesa;   
}

void addItem(Spesa spesa, Item item) {
    spesa->spesa[spesa->elementi]=item;
    spesa->elementi++;
}

Item removeItem(Spesa spesa, Item item) {
    for(int i=0;i<spesa->elementi;i++) {
        if(spesa->spesa[i]==item) {
            for(;i<spesa->elementi;i++) {
                spesa->spesa[i]=spesa->spesa[i+1];
                spesa->elementi--;
                return item;
            }
        }
    }
    printf("Item non trovato\n");
    return NULL;
}

float calcolaSpesa(Spesa spesa) {
    float total=0;
    for(int i=0;i<spesa->elementi;i++) {
        total+=returnPrice(spesa->spesa[i]);
    }
    return total;
}

void outputSpesa(Spesa spesa) {
    for(int i=0;i<spesa->elementi;i++) outputItem(spesa->spesa[i]);
}