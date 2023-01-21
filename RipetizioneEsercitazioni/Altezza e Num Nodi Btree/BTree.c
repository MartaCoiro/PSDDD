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





int getAltezza(BTree b){
    int left,right;
    if(isEmptyTree(b) || (isEmptyTree(b->right) && isEmptyTree(b->right)))
        return 0;
    else{
        left=getAltezza(b->left);
        right=getAltezza(b->right);
        if(left>right)
            return left+1;
        else
            return right+1;
    }

}
int getNumNodi(BTree b){
    int counter=1;
    if(isEmptyTree(b))
        return 0;
    else{
        if(getLeft(b)!=NULL)
            counter+=getNumNodi(b->left);
        if(getRight(b)!=NULL)
            counter+=getNumNodi(b->right);
        return counter;
    }

}