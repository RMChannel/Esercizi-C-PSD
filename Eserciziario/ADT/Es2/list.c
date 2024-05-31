#include <stdio.h>
#include <stdlib.h>
#include "libro.h"
#include "list.h"


struct list {
	int size;
	struct node *head;
};

struct node {
	Libro libro;
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

void addHead(List list, Libro libro) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->libro=libro;
    new_node->next=list->head;
    list->head=new_node;
    ++(list->size);
}

Libro removeHead(List list) {
    if (isEmpty(list))
    		return NULL;
    struct node *temp_node = list->head;
    list->head=temp_node->next;
    Libro libro=temp_node->libro;
    free(temp_node);
    --(list->size);
    return libro;
}

Libro getHead(List list){
    if (isEmpty(list)) return NULL;
    return list->head->libro;
}

int sizeList(List list){
    return list->size;
}

void printList(List list) {
	for(struct node *m=list->head;m!=NULL;m=m->next) printLibro(m->libro);
}

int existLibro(List list, Libro libro) {
	for(struct node *m=list->head;m!=NULL;m=m->next) {
		if(m->libro==libro) return 1;
	}
	return 0;
}

int addListLibro(List list, Libro libro, int pos){
	if(pos<0 || pos> sizeList(list)){
		fprintf(stderr,"posizione non valida");
		return 0;
	}

	if(pos==0){
		addHead(list,libro);
		return 1;
	}

	struct node *m,*succ,*n=malloc(sizeof(struct node));
	n->libro=libro;

	int posizione=0;
	for(m=list->head;m!=NULL && posizione<pos-1;m=m->next,posizione++);
	succ=m->next;
	m->next=n;
	n->next=succ;
	list->size+=1;
	return 1;
}

int addListTail(List list, Libro libro) {
	return addListLibro(list,libro,sizeList(list));
}

Libro removeListLibro(List list, Libro libro) {
	Libro temp;
	if (isEmpty(list))
		return NULL;
	struct node *p,*prev;
    for (p=list->head; p!=NULL; prev=p, p=p->next){
       if (libro==p->libro){
			if(p==list->head)
				return removeHead(list);
			prev->next = p->next;
			temp = p->libro;
			free (p);
			list->size--;
			return temp;
	   }
	
	}
	return NULL;
}

Libro getNext(List list, Libro libro) {
	struct node *m;
	for(m=list->head;m!=NULL;m=m->next) {
		if(m->libro==libro) break;
	}
	if(m==NULL || m->next==NULL) return NULL;
	return m->next->libro;
}