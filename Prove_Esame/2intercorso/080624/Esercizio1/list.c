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

/*
Questa funzione è quella che si occupa di trovare i due massimi all'interno della lista, prende in input solo la lista e restituisce un array
di due item contenenti il primo e il secondo massimo
*/
Item *dueMassimo(List list) { 
	if(list->size==0) { //Se la lista è vuota
		Item *a=malloc(sizeof(Item)*2);
		a[0]=""; //Restituisco i due massimi vuoti
		a[1]="";
		return a;
	}
	struct node *p=list->head;
	Item max1=p->item;
	Item max2=""; //Creo gli elementi max1 e max2, max1 viene preimpostato al 1°elemento della lista
	for(;p!=NULL;p=p->next) { //In caso contrario, inizio a controllare la lista
		if(cmpItem(max1,p->item)<0) { //Nel caso in cui l'item in p è maggiore di max1, allora max1 viene impostato a quell'elemento
			max2=max1; //Max2 viene impostato a max1, questo perché se max1 ha trovato un nuovo massimo, allora quello che è può essere il 2°massimo
			max1=p->item; //Imposto max1 al valore nuovo
		}
		else if(cmpItem(max2,p->item)<0 && cmpItem(max1,p->item)!=0) { //Invece se max2 è minore del valore dato, ma è diverso da max1
			max2=p->item; //Allora imposto max2 a quell'item
		}
	}
	Item *a=malloc(sizeof(Item)*2); //Mi creo l'array di item da restituire
	a[0]=max1; //Imposto i due massimi al suo interno
	a[1]=max2;
	return a; //Restituisco l'array
}

void printList(List list) {
	if(list->size==0) return;
	for(struct node *p=list->head;p!=NULL;p=p->next) outputItem(p->item);
}