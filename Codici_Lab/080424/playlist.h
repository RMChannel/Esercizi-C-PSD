#include "song.h"
#include "list.h"

typedef struct playlist *Playlist;

Playlist createPlaylist(char *name);
void addSong(Playlist, Song);
void removeSong( Playlist, char *);
void sortPlaylist(Playlist);
void printPlaylist(Playlist);