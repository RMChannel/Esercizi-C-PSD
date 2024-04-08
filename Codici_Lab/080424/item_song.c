#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"
#include"song.h"

Item inputItem() { //Crea due stringhe in memoria e un inter, prende l'input dall'utente e associa questi valori all'interno di una canzone e la restituisce
    char *titolo=malloc(sizeof(char)*100);
    char *autore=malloc(sizeof(char)*100);
    int durata;
    printf("Inserisci il titolo: ");
    scanf("%[^\n]",titolo);
    getchar();
    printf("Inserisci l'autore: ");
    scanf("%[^\n]",autore);
    getchar();
    printf("Inserisci la durata: ");
    scanf("%d",&durata);
    getchar();
    return initSong(titolo,autore,durata);
}

void outputItem(Item item) { //Stampa una canzone
    printf("Titolo: %s\nAutore: %s\nDurata: %d\n",title(item),artist(item),duration(item));
}

int cmpItem(Item item1, Item item2) { //Confronta il titolo di ogni canzone
    return strcmp(title(item1),title(item2));
}