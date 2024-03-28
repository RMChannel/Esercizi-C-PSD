#include <stdlib.h>
#include "list.h"
#include "item.h"


struct list {
    int size;
    struct node *head;
};

struct node {
    Item value;
    struct node *next;
};


List newList(){
    List list=malloc(sizeof(struct list));
    list->size = 0;
    list->head = NULL;
    
    return list;
}

int isEmpty(List list){
    return list->size==0;
}

void addHead(List list, Item item){
    struct node *newNode= malloc(sizeof(struct node));
    newNode->value = item;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

Item removeHead(List list){
    if (isEmpty (list)) return NULL;
    struct node *temp= list->head;
    list->head = temp->next;
    Item item = temp->value;
    free (temp);
    list->size--;
    return item;
}

Item getHead(List list){
    if (isEmpty (list)) return NULL;
    return list->head->value;
}

int sizeList(List list){
    return list->size;
}

void printList(List list){
    struct node *p;
    for (p=list->head; p!=NULL; p=p->next)
        outputItem(p->value);

}

Item searchListItem(List list, Item item, int *pos) {
    struct node *p;
    *pos=0;
    for (p=list->head; p!=NULL; p=p->next,(*pos)++) {
        if (cmpItem(item,p->value)==0) return p->value;
    }
    *pos=-1;
    return NULL;
}

Item removeListItem(List list, Item item) {
    if (isEmpty(list)) return NULL;
    Item temp;
    struct node *p, *prev;
    for (p=list->head; p!=NULL;prev=p, p=p->next) {
        if (cmpItem(item,p->value)==0) {
            if (p==list->head) return removeHead(list);
            prev->next=p->next;
            temp=p->value;
            free(p);
            list->size--;
            return temp;
        }
    }
    return NULL;
}

Item removeListPos(List list, int pos) {
    if (isEmpty(list) || (pos<0) || (pos>=sizeList(list))) return NULL;
    Item temp;
    struct node *p, *prev;
    int cont=0;
    for (p=list->head; p!=NULL;prev=p, p=p->next, cont++) {
        if (pos==cont) {
            if (p==list->head) return removeHead(list);
            prev->next=p->next;
            temp=p->value;
            free(p);
            list->size--;
            return temp;
        }
    }
    return NULL;
}