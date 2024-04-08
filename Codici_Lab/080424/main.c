#include <stdio.h>
#include "item.h"
#include "song.h"
#include "playlist.h"

int main(int argc, char *argv) {
    Song canzone;
    Playlist playlist=createPlaylist("Rock"); //Creo la playlist
    for (int i=0;i<5;i++) { //Inserisco 5 canzoni
        printf("Inserisci la %d canzone:\n",i+1);
        canzone=inputItem();
        addSong(playlist,canzone);
    }
    sortPlaylist(playlist); //ordino la playlist e la stampo
    printf("\n\n");
    printPlaylist(playlist);
}