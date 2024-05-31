#include <stdio.h>
#include <stdlib.h>
#include "song.h"
#include "list.h"


struct list {
	int size;
	struct node *head;
};

struct node {
	Song song;
	struct node *next;
};

List newList() {
    List list = malloc(sizeof(struct list));
    list->size=0;
    list->head=NULL;
    return list;
}

int isEmpty(List list) {
    return (list->size==0);
}

void addHead(List list, Song song) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->song=song;
    new_node->next=list->head;
    list->head=new_node;
    ++(list->size);
}

Song removeHead(List list) {
    if (isEmpty(list))
    		return NULL;
    struct node *temp_node = list->head;
    list->head=temp_node->next;
    Song song=temp_node->song;
    free(temp_node);
    --(list->size);
    return song;
}

Song getHead(List list){
    if (isEmpty(list)) return NULL;
    return list->head->song;
}

int sizeList(List list){
    return list->size;
}

void printList(List list) {
	for(struct node *m=list->head;m!=NULL;m=m->next) printSong(m->song);
}

int existSong(List list, Song song) {
	for(struct node *m=list->head;m!=NULL;m=m->next) {
		if(m->song==song) return 1;
	}
	return 0;
}

int addListSong(List list, Song song, int pos){
	if(pos<0 || pos> sizeList(list)){
		fprintf(stderr,"posizione non valida");
		return 0;
	}

	if(pos==0){
		addHead(list,song);
		return 1;
	}

	struct node *m,*succ,*n=malloc(sizeof(struct node));
	n->song=song;

	int posizione=0;
	for(m=list->head;m!=NULL && posizione<pos-1;m=m->next,posizione++);
	succ=m->next;
	m->next=n;
	n->next=succ;
	list->size+=1;
	return 1;
}

int addListTail(List list, Song song) {
	return addListSong(list,song,sizeList(list));
}

Song removeListSong(List list, Song song) {
	Song temp;
	if (isEmpty(list))
		return NULL;
	struct node *p,*prev;
    for (p=list->head; p!=NULL; prev=p, p=p->next){
       if (song==p->song){
			if(p==list->head)
				return removeHead(list);
			prev->next = p->next;
			temp = p->song;
			free (p);
			list->size--;
			return temp;
	   }
	
	}
	return NULL;
}

Song getNext(List list, Song song) {
	struct node *m;
	for(m=list->head;m!=NULL;m=m->next) {
		if(m->song==song) break;
	}
	if(m==NULL || m->next==NULL) return NULL;
	return m->next->song;
}