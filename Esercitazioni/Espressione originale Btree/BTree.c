#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "item.h"
#include "BTree.h"
#include "stack.h"

struct node{
    Item item;
    struct node *left;
    struct node *right;
};

BTree newTree(){
    return NULL;
}
int isEmptyTree(BTree btree){
    if(btree==NULL)
        return 1;
    return 0;
}
BTree buildTree(BTree b1, BTree b2 , Item item){
    BTree b=malloc(sizeof(struct node));
    b->item=item;
    b->left=b1;
    b->right=b2;
    return b;
}
Item getBTreeRoot(BTree b){
    if(isEmptyTree(b))
        return NULL;
    return b->item;
}
BTree getLeft(BTree b){
    if(isEmptyTree(b))
        return NULL;
    return b->left;
}
BTree getRight(BTree b){
    if(isEmptyTree(b))
        return NULL;
    return b->right;
}
void preOrder(BTree b){
    if(!isEmptyTree(b)){
        outputItem(b->item);
        preOrder(b->left);
        preOrder(b->right);
    }
    
}
void postOrder(BTree b){
    if(!isEmptyTree(b)){
        postOrder(b->left);
        postOrder(b->right);
        outputItem(b->item);
    }
}
void inOrder(BTree b){
    if(!isEmptyTree(b)){
        inOrder(b->left);
        outputItem(b->item);
        inOrder(b->right);
    }
}

int isNumber(BTree b){
    char* value=b->item;
    if(isdigit(*value))
        return 1;
    return 0;
}
/**
 * @brief Visita in Order
 * 
 * @param b 
 */
void printEspressioneOriginaleRecursive(BTree b){
    if(!isEmptyTree(b)){
        if(getRight(b) && getLeft(b) &&(isNumber(b->left) || isNumber(b->right)))
            printf("(");
        printEspressioneOriginaleRecursive(b->left);
        outputItem(b->item),
        printEspressioneOriginaleRecursive(b->right);
        if(getRight(b) && getLeft(b) && (isNumber(b->left) || isNumber(b->right)))
            printf(")");
    }
}

