#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "song.h"
#include "playlist.h"

struct playlist {
    char name[100];
    List list;
};

Playlist createPlaylist(char *name) { //Crea la playlist in memoria, gli da un nome e una lista e la restituisce in memoria
    Playlist playlist=malloc(sizeof(struct playlist));
    strcpy(playlist->name,name);
    playlist->list=newList();
    return playlist;
}

void addSong(Playlist playlist, Song song) { //Aggiunge una canzone alla playlist
    addHead(playlist->list,song);
}

void removeSong(Playlist playlist, char *title) { //Rimuove una canzone dalla playlist, partendo dal titolo creiamo un canzone con solo il titolo e facciamo l'eliminazione dalla lista, perché il cmpitem controlla solo il titolo della canzone e di conseguenza fa la ricerca a noi necessaria.
    Song songSearch=initSong(title,"",0);
    removeListItem(playlist->list,songSearch);
    free(songSearch);
}

void sortPlaylist(Playlist playlist) { //Ordina la playlist
    bubbleSortList(playlist->list);
}

void printPlaylist(Playlist playlist) { //Stampa ogni canzone con titolo, artista e durata
    struct node *p;
    printList(playlist->list);
}