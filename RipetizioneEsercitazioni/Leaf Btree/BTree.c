#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include "BTree.h"

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

void printLeaf(BTree b){
    if(getLeft(b)==NULL && getRight(b)==NULL){
        printf("Dentro l'if");
        outputItem(b->item);
        printf("Stampa");
    }
    else{
        printLeafIterative(b->left);
        printLeafIterative(b->right);
    }
    
}
void printLeafRecursive(BTree b){
    //outputItem(b->item);
    if(!isEmptyTree(b))
        printLeaf(b);
}
void printLeafIterative(BTree b){
    Stack stack=newStack();
    push(stack,b);
    while(!isEmptyStack(stack)){
        BTree bTemp=top(stack);
        if(getLeft(bTemp)==NULL && getRight(bTemp)==NULL)
            outputItem(bTemp->item);
        pop(stack);
        if(getRight(bTemp)!=NULL)
            push(stack,getRight(bTemp));
        if(getLeft(bTemp)!=NULL)
            push(stack,getLeft(bTemp));
    }
}

int countLeaf(BTree b){
    if(!b)
        return 0;
    else{
        if(getLeft(b)==NULL && getRight(b)==NULL)
            return 1;
        else return countLeaf(b->left)+ countNumLeaf(b->right);
    }
}
int countNumLeaf(BTree b){
    
    if(!isEmptyTree(b)){
        return countLeaf(b);
    }
    return 0;
}