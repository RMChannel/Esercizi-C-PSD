#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);
BTree newRandomTree(int);

void printTree(BTree);

void setLeft(BTree tree, BTree newTree);
void setRight(BTree tree, BTree newTree);