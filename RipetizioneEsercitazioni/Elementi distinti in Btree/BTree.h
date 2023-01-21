#include "item.h"
#include "list.h"

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

int altezzaBtree(BTree);
int nodiBtree(BTree);
void visitaPerLivelli(BTree);

void preOrderIterativo(BTree);
void postOrderIterativo(BTree);
void inOrderIterativo(BTree);

int countDistinctRecursive(BTree,List);
int countDistinctIterative(BTree);
