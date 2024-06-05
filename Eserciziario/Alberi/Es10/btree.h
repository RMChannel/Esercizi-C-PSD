#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);

BTree newRandomTree(int);
void printPerLevel(BTree bt);
void printTree(BTree);
int countNodes(BTree t);
int identyAlbero(BTree t1, BTree t2);