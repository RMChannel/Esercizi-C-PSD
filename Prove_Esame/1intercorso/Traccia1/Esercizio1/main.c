#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "playlist.h"

// utilizzare questa funzione nel main per <stampare, ordinare, stampare> la playlist
// da completare riga ***
void stampaEordina(Playlist pl){
	printf("\n-- Stampa playlist originale --\n");
	printPlaylist(pl);
	printf("\n-- Stampa playlist dopo ordinamento per gradimento --\n");

	// *** inserire qui la chiamata all'operatore che ordina la playlist per gradimento
	sortByGradimento(pl);

	printPlaylist(pl);
	printf("\n\n");
}

// funzione che restituisce un numero intero tra 1 e 100
int randomInt() {
	return 1 + (rand() % 100);
}

int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga
	// completare
	Playlist pl=createPlaylist("Test");
	Song s1=initSong("Test1","Test1",200,200);
	Song s2=initSong("Test2","Test2",400,400);
	Song s3=initSong("Test3","Test3",300,300);
	Song s4=initSong("Test4","Test4",500,500);
	Song s5=initSong("Test5","Test5",100,100);
	addSong(pl,s1);
	addSong(pl,s2);
	addSong(pl,s3);
	addSong(pl,s4);
	addSong(pl,s5);
	stampaEordina(pl);
}