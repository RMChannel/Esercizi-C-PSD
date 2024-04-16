#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"
#include "libro.h"
#define N 100

Item inputItem() {
    char *autore=malloc(sizeof(char)*N);
    char *titolo=malloc(sizeof(char)*N);
    char *editore=malloc(sizeof(char)*N);
    int *anno=malloc(sizeof(int));
    printf("Inserisci l'autore: ");
    scanf("%[^\n]",autore);
    getchar();
    printf("Inserisci il titolo: ");
    scanf("%[^\n]",titolo);
    getchar();
    printf("Inserisci l'editore: ");
    scanf("%[^\n]",editore);
    getchar();
    printf("Inserisci l'anno: ");
    scanf("%d",anno);
    getchar();
    return initLibro(autore,titolo,editore,anno);
}

Item createItem(char *autore2, char *titolo2, char *editore2, int anno2) {
    char *autore=malloc(sizeof(char)*N);
    char *titolo=malloc(sizeof(char)*N);
    char *editore=malloc(sizeof(char)*N);
    int *anno=malloc(sizeof(int));
    strcpy(autore,autore2);
    strcpy(titolo,titolo2);
    strcpy(editore,editore2);
    *anno=anno2;
    return initLibro(autore,titolo,editore,anno);
}

void outputItem(Item libro) {
    printf("Autore: %s\nTitolo: %s\nEditore: %s\nAnno: %d\n",autore(libro),titolo(libro),editore(libro),anno(libro));
}

int compareItem(Item libro1, Item libro2) {
    return strcmp(titolo(libro1),titolo(libro2));
}