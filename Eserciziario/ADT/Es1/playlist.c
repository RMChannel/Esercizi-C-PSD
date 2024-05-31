#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include "song.h"

struct playlist{
    Song songs[100];
    Song reproducing;
    int size;
};

Playlist newPlaylist() {
    Playlist playlist=malloc(sizeof(Playlist));
    playlist->reproducing=NULL;
    playlist->size=0;
    return playlist;
}

void addSong(Playlist playlist, Song song) {
    int i;
    for(i=0;i<playlist->size;i++);
    playlist->songs[i]=song;
    playlist->size++;
}

void removeSong(Playlist playlist, Song song) {
    for(int i=0;i<playlist->size;i++) {
        if (song==playlist->songs[i]) {
            for(;i<playlist->size;i++) {
                playlist->songs[i]=playlist->songs[i+1];
            }
            break;
        }
    }
    playlist->size--;
}

void printPlaylist(Playlist playlist) {
    printf("%d",playlist->size);
    for(int i=0;i<playlist->size;i++) printSong(playlist->songs[i]);
}

int isReproducing(Playlist playlist) {
    return (playlist->reproducing)!=NULL;
}

void stop(Playlist playlist) {
    playlist->reproducing=NULL;
}

void riproduci(Playlist playlist, Song song) {
    Song temp=playlist->reproducing;
    int i;
    for(i=0;i<playlist->size;i++) if(temp==playlist->songs[i]) break;
    i++;
    temp=playlist->songs[i];
    if(temp!=NULL)  playlist->reproducing=song;
}

void skip(Playlist playlist) {
    Song temp=playlist->reproducing;
    int i;
    for(i=0;i<playlist->size;i++) if(temp==playlist->songs[i]) break;
    i++;
    temp=playlist->songs[i];
    if(temp==NULL) printf("Nessuna canzone rimasta nella playlist\n");
    else playlist->reproducing=temp;
}