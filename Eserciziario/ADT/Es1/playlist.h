#include "song.h"

typedef struct playlist *Playlist;

Playlist newPlaylist();
void addSong(Playlist, Song);
void removeSong(Playlist, Song);
void printPlaylist(Playlist);
void riproduci(Playlist, Song);
int isReproducing(Playlist);
void stop(Playlist);
void skip(Playlist);