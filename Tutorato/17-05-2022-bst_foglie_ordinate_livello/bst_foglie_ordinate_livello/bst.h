#include <stdlib.h>
#include "item.h"

typedef struct node *BST;

BST newBST();
int isEmptyBST(BST);
BST getLeft(BST);
BST getRight(BST);
Item getItem(BST);
Item search(BST, Item);
void preOrder(BST);
void inOrder(BST);
void postOrder(BST);
Item min(BST);
Item max(BST);
void insertBST(BST *, Item);
Item deleteBST(BST *, Item);
void printPerLevel(BST);
int is_k_balanced(BST,u_int32_t);
void print_leaf_ordered(BST);
