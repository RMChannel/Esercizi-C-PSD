#include <stdlib.h>
#include "btree.h"
#include "item.h"

struct node{
  Item value;
  struct node* left;
  struct node* right;
};

BTree newTree(){
  return NULL;
}

int isEmptyTree(BTree tree){
  if(tree==NULL)
    return 1;
  else
    return 0;
}

BTree buildTree(BTree left, BTree right, Item i){
  BTree tree=malloc(sizeof(struct node));
  tree->left=left;
  tree->right=right;
  tree->value=i;
  return tree;
}

Item getBTreeRoot(BTree tree){
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->value;
}

BTree getLeft(BTree tree){
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->left;
}

BTree getRight(BTree tree){
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->right;
}

void preOrder(BTree tree){
  if(!isEmptyTree(tree)){
    outputItem(tree->value);
    preOrder(tree->left);
    preOrder(tree->right);
  }
}

void postOrder(BTree tree){
  if(!isEmptyTree(tree)){
    postOrder(tree->left);
    postOrder(tree->right);
    outputItem(tree->value);
  }
}

void inOrder(BTree tree){
  if(!isEmptyTree(tree)){
    inOrder(tree->left);
    outputItem(tree->value);
    inOrder(tree->right);
  }
}