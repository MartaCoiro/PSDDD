#include "item.h"
#include "list.h"
typedef struct node *BST;

BST newBTS();
int isEmptyBST(BST);
BST getLeft(BST);
BST getRight(BST);
Item getItem(BST);
Item search(BST,Item);
Item min(BST);
Item max(BST);
void preOrder(BST);
void inOrder(BST);
void postOrder(BST);
void insertBST(BST*,Item);
Item deleteBST(BST*,Item);
int nodi(BST);

List listaOrdinata(BST);
void order(BST,List);
List listaOrdinataIterativa(BST);
Item primiDueElementi(BST);
Item ultimiDueElementi(BST);