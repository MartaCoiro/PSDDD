#include <stdio.h>
#include <stdlib.h>
#include "item.h"
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

int getNumNodi(BTree b){
    int counter=1;
    if(!b)
        return 0;
    else{
        if(!isEmptyTree(b->left))
            counter+=getNumNodi(b->left);
        if(!isEmptyTree(b->right))
            counter+=getNumNodi(b->right);
    }
    return counter;
    
}
int altezzaBtree(BTree b){
    int left,right;
    if(isEmptyTree(b) || (isEmptyTree(getLeft(b)) && isEmptyTree(getRight(b))))
        return 0;
    else{
        left=altezzaBtree(b->left);
        right=altezzaBtree(b->right);
        if(left<right)
            return 1+right;
        else{
            return 1+left;
        }
    }
}