#include <stdlib.h>
#include <stdio.h>
#include "libreria.h"
#include "libro.h"

struct libreria{
    Libro libri[100];
    int size;
};

Libreria createLibreria() {
    Libreria libreria=malloc(sizeof(struct libreria));
    libreria->size=0;
    return libreria;
}

void addLibro(Libreria lib, Libro book) {
    int i;
    for(i=0;i<lib->size;i++);
    lib->libri[i]=book;
    lib->size++;
}

void printLibreria(Libreria lib) {
    printf("%d",lib->size);
    for(int i=0;i<lib->size;i++) outputLibro(lib->libri[i]);
}

Libro searchForTitle(Libreria lib, char *s) {
    for(int i=0;i<lib->size;i++) if(cmpTitolo(s,lib->libri[i])) return lib->libri[i];
    return NULL;
}

Libro searchForAuthor(Libreria lib, char *s) {
    for(int i=0;i<lib->size;i++) if(cmpAutore(s,lib->libri[i])) return lib->libri[i];
    return NULL;
}