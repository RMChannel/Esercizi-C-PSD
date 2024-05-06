#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);
void preOrder(BTree);
void postOrder(BTree);
void inOrder(BTree);
int numberOfNodi(BTree);
int Height(BTree);
void printLevel(BTree);
void preOrderIterative(BTree);
void postOrderIterative(BTree);
void SimmetricOrderIterative(BTree);