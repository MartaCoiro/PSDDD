#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "BTree.h"
#include "list.h"

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

void leaf(BTree b,List l){
    if(getLeft(b)==NULL && getRight(b)==NULL){
        addHead(l,b->item);
        //outputItem(b->item);
    }
    else{
        leaf(b->left,l);
        leaf(b->right,l);
    }
}

List leafInList(BTree b){
    List list=newList();
    if(!isEmptyTree(b))
        leaf(b,list);
    return list;
}


/*
void printLeaf(BTree b){
    
    if(getLeft(b)==NULL && getRight(b)==NULL){
        outputItem(b->item);
    }
    else{
        printLeaf(getLeft(b));
        printLeaf(getRight(b));
    }
    
}

void printLeafOrder(BTree bst){
    printLeaf(bst);
}
*/