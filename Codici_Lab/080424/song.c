#include <stdlib.h>
#include <stdio.h>
#include "song.h"
#include "item.h"

struct song {
    char *title;
    char *artist;
    int duration;
};

Song initSong(char *title, char *artist, int duration) { //Dati il titolo, l'autore e la durata della canzone, assegna ad una nuova canzone in memoria questi valori e la restituisce
    Song canzone=malloc(sizeof(struct song));
    canzone->title=title;
    canzone->artist=artist;
    canzone->duration=duration;
    return canzone;
}

char *title(Song song) { //restituisce il titolo della canzone
    return song->title;
}

char *artist(Song song) { //restituisce l'artista della canzone
    return song->artist;
}

int duration(Song song) { //restituisce la durata della canzone
    return song->duration;
}