#include <stdlib.h>
#include "libro.h"

struct Libro {
    char *autore;
    char *titolo;
    char *editore;
    int anno;
};

Libro initLibro(char *autore, char *titolo, char *editore, int *anno) {
    Libro libro=malloc(sizeof(struct Libro));
    libro->autore=autore;
    libro->titolo=titolo;
    libro->editore=editore;
    libro->anno=*anno;
    return libro;
}

char *autore(Libro libro) {
    return(libro->autore);
}

char *titolo(Libro libro) {
    return(libro->titolo);
}

char *editore(Libro libro) {
    return(libro->editore);
}

int anno(Libro libro) {
    return(libro->anno);
}