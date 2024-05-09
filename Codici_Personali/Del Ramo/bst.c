#include "bst.h"
#include "item.h"
#include "queue.h"
#include <stdlib.h>

struct node{
  Item value;
  struct node* left;
  struct node* right;
};

BST newBST(){
  return NULL;
}

int isEmptyBST(BST tree){
  if(tree==NULL)
    return 1;
  else
    return 0;
}

Item getItem(BST tree){
  if(isEmptyBST(tree))
    return NULL;
  else
    return tree->value;
}

BST getLeft(BST tree){
  if(isEmptyBST(tree))
    return NULL;
  else
    return tree->left;
}

BST getRight(BST tree){
  if(isEmptyBST(tree))
    return NULL;
  else
    return tree->right;
}

Item search(BST tree, Item item) {
  if (isEmptyBST(tree)) return NULL;
  else if (cmpItem(item,tree->value)==0) return tree->value;
  else if (cmpItem(item,tree->value)>0) return search(tree->right,item);
  else return search(tree->left,item);
}

Item min(BST tree) {
  if(isEmptyBST(tree)) return NULL;
  else if(isEmptyBST(tree->left)) return tree->value;
  else return min(tree->left);
}

Item max(BST tree) {
  if(isEmptyBST(tree)) return NULL;
  else if(isEmptyBST(tree->right)) return tree->value;
  else return min(tree->right);
}

void insertBST(BST *tree, Item item) {
  if (isEmptyBST(*tree)) {
    *tree=malloc(sizeof(struct node));
    (*tree)->left=NULL;
    (*tree)->right=NULL;
    (*tree)->value=item;
  }
  else if (cmpItem(item,(*tree)->value)<0) insertBST(&((*tree)->left),item);
  else insertBST(&((*tree)->right),item);
}

BST *findTree(BST *tree, Item item, BST *lastTree) {
  if (isEmptyBST(*tree)) return NULL;
  else if (cmpItem(item,(*tree)->value)==0) return tree;
  else if (cmpItem(item,(*tree)->value)>0) return findTree(&(*tree)->right,item,tree);
  else return findTree(&(*tree)->left,item,tree);
}

void deleteAll(BST *tree, Item item) {
  if(!isEmptyBST((*tree)->left)) deleteAll(&(*tree)->left,item);
  if(!isEmptyBST((*tree)->right)) deleteAll(&(*tree)->right,item);
  free((*tree));
}

Item deleteBST(BST *tree, Item item) {
  BST *before=tree;
  BST *found=findTree(tree,item,before);
  if ((*found)==NULL) return NULL;
  else {
    if(((*before)->left->value)==((*found)->value)) (*before)->left=NULL;
    else (*before)->right=NULL;
    deleteAll(found,item);
    return item;
  }
}

void printLevel(BST tree) {
  if(isEmptyBST(tree)) return;
  Queue queue=newQueue();
  enqueue(queue,tree);
  while(!isEmptyQueue(queue)) {
    BST temp=dequeue(queue);
    if(!isEmptyBST(temp->left)) enqueue(queue,temp->left);
    if(!isEmptyBST(temp->right)) enqueue(queue,temp->right);
    outputItem(temp->value);
  }
  free(queue);
}