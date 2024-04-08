#include "item.h"
typedef struct song *Song;

Song initSong(char *title, char *author, int duration);
char *title(Song);
char *artist(Song);
int duration(Song);