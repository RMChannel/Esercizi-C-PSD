#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"

struct song{
    char *titolo;
    char *artista;
    char *album;
    int durata;
};

Song createSong(char *titolo, char *artista, char *album, int durata) {
    Song newSong=malloc(sizeof(Song));
    char *title=malloc(sizeof(titolo));
    strcpy(title,titolo);
    char *artist=malloc(sizeof(artista));
    strcpy(artist,artista);
    char *alb=malloc(sizeof(album));
    strcpy(alb,album);
    newSong->titolo=title;
    newSong->artista=artist;
    newSong->album=alb;
    newSong->durata=durata;
    return newSong;
}

void printSong(Song song) {
    printf("Titolo: %s\nArista: %s\nAlbum: %s\nDurata: %d\n",song->titolo,song->artista,song->album,song->durata);
}