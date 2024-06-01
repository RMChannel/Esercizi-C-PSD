#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node{
    struct node *next;
    struct node *prev;
    int value;
};

struct list{
    struct node *head;
    struct node *tail;
    int size;
};

List newList() {
    List list=malloc(sizeof(struct list));
    list->size=0;
    list->head = NULL;
    list->tail =NULL;
    return list;
}

int isEmpty(List list) {
    return list->size==0;
}

void addHead(List list, int n) {
    struct node *nodo=malloc(sizeof(struct node));
    nodo->value=n;
    nodo->next=list->head;
    if(list->head!=NULL) list->head->prev=nodo;
    else list->tail=nodo;
    nodo->prev=NULL;
    list->size++;
    list->head=nodo;
}

void addTail(List list, int n) {
    struct node *nodo=malloc(sizeof(struct node));
    nodo->value=n;
    nodo->next=NULL;
    nodo->prev=list->tail;
    if(list->tail!=NULL) list->tail->next=nodo;
    else list->head=nodo;
    list->tail=nodo;
    list->size++;
}

void addInPos(List list, int n, int pos) {
    if(pos>=list->size) return;
    int i;
    struct node*p;
    for(p=list->head,i=0;i<pos;p=p->next,i++);
    struct node *nodo=malloc(sizeof(struct node));
    nodo->value=n;
    nodo->next=p;
    nodo->prev=p->prev;
    nodo->prev->next=nodo;
    nodo->next->prev=nodo;
    list->size++;
}

int removeItem(List list, int n) {
    struct node*p=list->head;
    for(;p->value!=n && p!=NULL;p=p->next);
    if(p==NULL) return -1;
    p->prev->next=p->next;
    p->next->prev=p->prev;
    return p->value;
}

void printList(List list) {
    for(struct node *p=list->head;p!=NULL;p=p->next) printf("%d ",p->value);
}