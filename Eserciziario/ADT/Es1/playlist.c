#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include "song.h"
#include "list.h"

struct playlist{
    List list;
    Song reproducing;
};

Playlist newPlaylist() {
    Playlist playlist=malloc(sizeof(Playlist));
    playlist->list=newList();
    playlist->reproducing=NULL;
    return playlist;
}

void addSong(Playlist playlist, Song song) {
    addHead(playlist->list,song);
}

void removeSong(Playlist playlist, Song song) {
    removeListSong(playlist->list,song);
}

void printPlaylist(Playlist playlist) {
    printList(playlist->list);
}

int isReproducing(Playlist playlist) {
    return (playlist->reproducing)!=NULL;
}

void stop(Playlist playlist) {
    playlist->reproducing=NULL;
}

void riproduci(Playlist playlist, Song song) {
    if(existSong(playlist->list,song))  playlist->reproducing=song;
}

void skip(Playlist playlist) {
    Song temp=getNext(playlist->list,playlist->reproducing);
    if(temp==NULL) printf("Nessuna canzone rimasta nella playlist\n");
    else playlist->reproducing=temp;
}