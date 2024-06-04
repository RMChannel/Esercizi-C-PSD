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

void setLeft(BTree t, BTree t2);
void setRight(BTree t, BTree t2);