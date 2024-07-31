#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"


struct list {
	int size;
	struct node *head;
};

struct node {
	Item item;
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

void addHead(List list, Item item) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->item=item;
    new_node->next=list->head;
    list->head=new_node;
    ++(list->size);
}

Item removeHead(List list) {
    if (isEmpty(list))
    		return NULL;
    struct node *temp_node = list->head;
    list->head=temp_node->next;
    Item item=temp_node->item;
    free(temp_node);
    --(list->size);
    return item;
}

Item getHead(List list){
    if (isEmpty(list)) return NULL;
    return list->head->item;
}

int sizeList(List list){
    return list->size;
}

int addListItem(List list, Item item, int pos){
	if(pos<0 || pos> sizeList(list)){
		fprintf(stderr,"posizione non valida");
		return 0;
	}

	if(pos==0){
		addHead(list,item);
		return 1;
	}

	struct node *m,*succ,*n=malloc(sizeof(struct node));
	n->item=item;

	int posizione=0;
	for(m=list->head;m!=NULL && posizione<pos-1;m=m->next,posizione++);
	succ=m->next;
	m->next=n;
	n->next=succ;
	list->size+=1;
	return 1;
}

int addListTail(List list, Item item){
	return addListItem(list,item,sizeList(list));
}

