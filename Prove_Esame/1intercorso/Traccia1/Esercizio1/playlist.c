#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "playlist.h"
#include "list.h"
#include "song.h"

struct playlist{
	char *name;
	List songs;
};


Playlist createPlaylist(char* name){
	Playlist p = malloc(sizeof(struct playlist));
	p->name = strdup(name);
	p->songs = newList();
	return p;
}

void addSong(Playlist p, Song s){
	addHead(p->songs, s);
}

void removeSong(Playlist p, char *title){
	Song s = initSong(title, "", 0, 0);
	removeListItem(p->songs, s);
}

void printPlaylist(Playlist p){
	printf("Playlist: %s", p->name);
	printList(p->songs);
	printf("\n");
}

void sortByGradimento(Playlist playlist) {
	List songs=playlist->songs;
	Song s1, s2;
	int n=sizeList(songs);
	for (int i=1;i<n;i++) {
		for (int j=0;j<(n-i);j++) {
			s1=getListItemPos(songs,j);
			s2=getListItemPos(songs,j+1);
			if (cmpSongs(s1,s2)) {
				Song temp=s1;
				s1=s2;
				s2=temp;
				setListItemPos(songs,j,s1);
				setListItemPos(songs,j+1,s2);
			}
		}
	}
}