#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);

BTree newRandomTree(int);
void printCharTree(BTree bt);
void printTree(BTree);
Item countNodes(BTree t, int i);