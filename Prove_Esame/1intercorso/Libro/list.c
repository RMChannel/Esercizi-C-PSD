#include <stdlib.h>
#include "item.h"
#include "list.h"
#define FALSE 0
#define TRUE 1

struct list
{
	int size;
	struct node *head;
};

struct node
{
	Item value;
	struct node *next;
};

List newList()
{
	List list = malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;

	return list;
}

int isEmpty(List l)
{
	return (l->size==0 ? 1 : 0);
}

void addHead(List l, Item a)
{
	struct node *n = malloc(sizeof(struct node));
	n->value = a;
	n->next = l->head;
	l->head = n;

	(l->size)++;
}
Item removeHead(List l)
{
	Item a;
	if(isEmpty(l))
		return NULL;

	struct node *tmp = l->head;
	l->head = l->head->next;
	a = tmp->value;
	free(tmp);
	(l->size)--;
	return a;
}

Item getHead(List l)
{
	if(isEmpty(l))
		return NULL;
	else
		return (l->head->value);
}
int sizeList(List l)
{
	return l->size;
}

void printList(List l)
{
	struct node *p;

	for(p = l->head; p != NULL; p = p->next)
		outputItem(p->value);
}

/* Funziona cerca elemento nella lista*/

Item searchList(List l, Item item, int *pos){
  *pos=0;
  struct node *p;
  for(p = l->head; p != NULL; p = p->next, (*pos)++)
    if(compareItem(item, p->value) == 0)
      return p->value;
  *pos = -1;

  return NULL;
}


/* Funzione rimuovi elemento dalla lista */

Item removeListItem(List l, Item item){
	if(isEmpty(l))
		return NULL;
	Item pp;
  struct node *p;
	struct node *prev;
  for(p = l->head; p != NULL; prev = p, p = p->next)
    if(compareItem(item, p->value) == 0)
    	if(p == l->head)
				return removeHead(l);
			else{
				prev->next = p->next;
				pp=p->value;
				free(p);
				(l->size)--;
				return pp;
			}

	return NULL;
}



Item removeListItemPos(List l, int pos){
	if(isEmpty(l))
		return NULL;
	int i=0;
	Item pp;
  struct node *p;
	struct node *prev;
	for(p = l->head; p != NULL; prev = p, p = p->next, i++)
    if(i == pos)
    	if(p == l->head)
				return removeHead(l);
			else{
				prev->next = p->next;
				pp=p->value;
				free(p);
				(l->size)--;
				return pp;
			}

	return NULL;
}

int addListItem (List l, Item e, int pos)
{
	struct node *p;
	int i;
	if(pos<0 || pos>(l->size))
		return 0;
	if(pos==0)
	{	
		addHead(l,e);
		return 1;
	}
	else
	{
		for(p = l->head, i=0; i < pos-1; i++, p = p->next)
			;
		struct node *newNode=malloc(sizeof(struct node));
		newNode->value=e;
		newNode->next=p->next;
		p->next=newNode;
		(l->size)++;
		return 1;
	}
}

int addListTail (List l, Item e)
{
	return addListItem(l,e,l->size);
}

void reverseList(List l)
{
	struct node *p,*prev=NULL,*temp;
	for(p = l->head; p != NULL; prev = p, p = temp)
	{
		temp=p->next;
		p->next=prev;
	}
	l->head=prev;
}
		
	
List cloneList(List l)
{
	struct node *p;
	List new=newList();
	for(p = l->head; p != NULL; p = p->next)
		addListTail(new,p->value);
	return new;
}

void swapItem(struct node *p1, struct node *p2) {
	Item temp=p1->value;
	p1->value=p2->value;
	p2->value=temp;
}

void bubbleSortList(List list) {
	struct node *p1, *p2;
	int n=list->size;
	int i,j,ordinato=FALSE;
	for (i=1;i<n;i++) {
		ordinato=TRUE;
		for (j=0, p1=list->head; j<(n-i); j++,p1=p1->next) {
			p2=p1->next;
			if (compareItem(p1->value,p2->value)>0) {
				ordinato=FALSE;
				swapItem(p1,p2);
			}
		}
	}
}