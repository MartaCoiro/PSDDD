#include "item.h"
#include "list.h"
typedef struct node *BST;

BST newBST();
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

void printLeafOrder(BST);
void printLeafOrderIterative(BST);
List leafInList(BST);
