#include <stdlib.h>
#include <stdio.h>
#include "alberi.h"
#include "item.h"
#define FALSE 0
#define TRUE 1

struct albero {
    int size;
    struct ramo *head;
};

struct ramo {
    Item value;
    struct ramo *left;
    struct ramo *right;
};

Ramo createRamo(Item item) {
    struct ramo *newNode=malloc(sizeof(struct ramo));
    newNode->value=item;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Ramo initAlbero(Albero albero, Item item) {
    albero->size=1;
    albero->head=createRamo(item);
    return albero->head;
}

Albero newAlbero() {
    Albero albero=malloc(sizeof(struct albero));
    albero->size=0;
    albero->head=NULL;
    return albero;
}

int createLeft(Ramo ramo, Albero albero, Item item) {
    if (ramo->left!=NULL) return -1;
    else {
        ramo->left=createRamo(item);
        albero->size++;
        return 1;
    }
}

int createRight(Ramo ramo, Albero albero, Item item) {
    if (ramo->right!=NULL) return -1;
    else {
        ramo->right=createRamo(item);
        albero->size++;
        return 1;
    }
}

int isEmpty(Albero albero) {
    return albero->size==0;
}

void printRamo(Ramo ramo) {
    printf("Ramo base: ");
    outputItem(ramo->value);
    printf("\nRamo sinistro: ");
    outputItem(ramo->left->value);
    printf("\nRamo destro: ");
    outputItem(ramo->right->value);
}