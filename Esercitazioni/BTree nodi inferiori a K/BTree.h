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

/**
 * @brief 
 * 
 * @return char* serve per il carattere separatore tipo : , - 
 */
char* concatNodeLessThen(BTree,Item,char*);
//Versione Ricorsiva
char * concatNodeLessThenIerativa(BTree,Item,char*);
