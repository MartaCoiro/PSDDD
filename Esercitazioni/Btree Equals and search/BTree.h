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

Item getMaxRecursive(BTree);
Item getMaxIterative(BTree);

int isEqualsTreeRecursive(BTree,BTree);
int isEqualsTreeIterative(BTree,BTree);

int searchItemRecursive(BTree,Item);
int searchItemIterative(BTree,Item);