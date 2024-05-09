#include "item.h"

typedef struct node *BST;

BST newBST();
int isEmptyBST(BST);
BST getLeft(BST);
BST getRight(BST);
Item getItem(BST);
Item search(BST, Item);
Item min(BST);
Item max(BST);
void insertBST(BST *, Item);
Item deleteBST(BST *, Item);
void printLevel(BST);
Item deleteBST(BST *, Item);