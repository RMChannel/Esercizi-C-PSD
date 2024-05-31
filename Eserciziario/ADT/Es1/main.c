#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include "song.h"

int main() {
    Song song=createSong("Stereo Hearts","Gym Class Heroes","Clasics",210);
    Song song2=createSong("L'altra Dimensione","Maneskins","Il ballo della vita",127);
    Song song3=createSong("Breathe","Olly Alexander","Years & Years",240);
    Playlist playlist=newPlaylist();
    addSong(playlist,song);
    addSong(playlist,song2);
    addSong(playlist,song3);
    riproduci(playlist,song3);
    skip(playlist);
    skip(playlist);
    skip(playlist);
    return 0;
}