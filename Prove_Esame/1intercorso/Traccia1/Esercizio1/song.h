typedef struct song *Song;

Song initSong(char* title, char* artist, int duration, int grad);
char* title(Song);
char* artist(Song);
int duration(Song);
int cmpSongs(Song s1, Song s2);