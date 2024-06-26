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
  else return max(tree->right);
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

Item deleteBST(BST *tree, Item item) {
  if (isEmptyBST(*tree)) return NULL;
  else if (cmpItem(item,(*tree)->value)<0) return deleteBST(&(*tree)->left,item);
  else if (cmpItem(item,(*tree)->value)>0) return deleteBST(&(*tree)->right,item);
  else {
    if (isEmptyBST((*tree)->left)) {
      Item tempItem=(*tree)->value;
      BST tempBST=(*tree);
      (*tree)=(*tree)->right;
      free(tempBST);
      return tempItem;
    }
    else if (isEmptyBST((*tree)->right)) {
      Item tempItem=(*tree)->value;
      BST tempBST=(*tree);
      (*tree)=(*tree)->left;
      free(tempBST);
      return tempItem;
    }
    else {
      Item maxItem=max((*tree)->left);
      Item tempItem=(*tree)->value;
      BST tempBST=(*tree);
      (*tree)->value=maxItem;
      deleteBST(&((*tree)->left),maxItem);
      return tempItem;
    }
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