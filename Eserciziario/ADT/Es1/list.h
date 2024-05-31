#include "song.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Song);
Song removeHead(List);
Song getHead(List);
int sizeList(List);
int addListTail(List, Song);
Song removeListSong(List, Song);
void printList(List);
int existSong(List, Song);
Song getNext(List, Song);