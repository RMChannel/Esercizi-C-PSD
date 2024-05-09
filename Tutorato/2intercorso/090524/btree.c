#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "queue.h"

struct node{
    Item value;
    struct node* left;
    struct node* right;
};

BTree newTree() {
    return NULL;
}
int isEmptyTree(BTree tree) {
    if (tree==NULL) return 1;
    else return 0;
}

BTree buildTree(BTree left, BTree right, Item item) {
    BTree t=malloc(sizeof(struct node));
    t->left=left;
    t->right=right;
    t->value=item;
    return t;
}

Item getBTreeRoot(BTree tree) {
    if(isEmptyTree(tree)) return NULL;
    else return tree->value;
}

BTree getLeft(BTree tree) {
    if(isEmptyTree(tree)) return NULL;
    else return tree->left;
}

BTree getRight(BTree tree) {
    if(isEmptyTree(tree)) return NULL;
    else return tree->right;
}

void preOrder(BTree tree) {
    if (!isEmptyTree(tree)) {
        outputItem(tree->value);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void postOrder(BTree tree) {
    if (!isEmptyTree(tree)) {
        postOrder(tree->left);
        postOrder(tree->right);
        outputItem(tree->value);
        }
}

void inOrder(BTree tree) {
    if (!isEmptyTree(tree)) {
        inOrder(tree->left);
        outputItem(tree->value);
        inOrder(tree->right);
    }
}

void printLevel(BTree tree) {
  Queue queue=newQueue(); //Ci creiamo una coda
  enqueue(queue,tree); //Aggiungiamo il ramo iniziale
  while(!isEmptyQueue(queue)) { //Finché la coda non è vuota
    BTree temp=dequeue(queue); //Ci prendiamo il 1°elemento della coda
    if(!isEmptyTree(temp->left)) enqueue(queue,temp->left); //Nel caso in cui esistano elementi a sinistra, li aggiungiamo
    if(!isEmptyTree(temp->right)) enqueue(queue,temp->right); //Stessa cosa a destra
    outputItem(temp->value); //E alla fine viene stampato tutto
  } //Questo ciclo viene ripetuto finchè non vengono stampati tutti gli elementi pian piano inseriti nella coda
  free(queue); //Infine liberiamo la memoria della coda, visto che non è più necessaria
}