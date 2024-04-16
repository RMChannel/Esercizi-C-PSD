#include <stdlib.h>
#include "catalogo.h"
#include "auto.h"
#include "list.h"

struct Catalogo {
    List cars;
};

Catalogo newCatalogo() {
    Catalogo catalogo=malloc(sizeof(struct Catalogo));
    catalogo->cars=newList();
    return catalogo;
}

void addCar(Catalogo catalogo, Auto car) {
    addHead(catalogo->cars,car);
}

void removeCar(Catalogo catalogo, Auto car) {
    removeListItem(catalogo->cars,car);
}

int searchCar(Catalogo catalogo, Auto car) {
    int n;
    searchListItem(catalogo->cars, car, &n);
    return n;
}

void ordinaCatalogo(Catalogo catalogo) {
    bubbleSortList(catalogo->cars);
}

void printCatalogo(Catalogo catalogo) {
    printList(catalogo->cars);
}