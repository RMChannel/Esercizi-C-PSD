#include <stdlib.h>
#include "list.h"
#include "libreria.h"

struct Libreria {
    List libri;
};

Libreria newLibreria() {
    Libreria libreria=malloc(sizeof(struct Libreria));
    libreria->libri=newList();
    return libreria;
}

void addLibro(Item libro, Libreria libreria) {
    addHead(libreria->libri,libro);
}

void outputLibreria(Libreria libreria) {
    printList(libreria->libri);
}

void ordinaLibreria(Libreria libreria) {
    bubbleSortList(libreria->libri);
}