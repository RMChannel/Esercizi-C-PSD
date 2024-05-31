#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

struct libro{
    char *titolo;
    char *autore;
    char *genere;
    int anno;
};

Libro createLibro(char *t, char *a, char *gen, int anno) {
    Libro libro=malloc(sizeof(struct libro));
    libro->anno=anno;
    char *title=malloc(sizeof(char)*50);
    char *author=malloc(sizeof(char)*50);
    char *genre=malloc(sizeof(char)*50);
    strcpy(title,t);
    strcpy(author,a);
    strcpy(genre,gen);
    libro->titolo=title;
    libro->autore=author;
    libro->genere=genre;
    return libro;
}

int cmpTitolo(char *s, Libro l) {
    return strcmp(s,l->titolo)==0;
}

int cmpAutore(char *s, Libro l) {
    return strcmp(s,l->autore)==0;
}

void outputLibro(Libro l) {
    printf("Titolo: %s\nAutore: %s\nGenere: %s\nAnno di pubblicazione: %d\n",l->titolo,l->autore,l->genere,l->anno);
}