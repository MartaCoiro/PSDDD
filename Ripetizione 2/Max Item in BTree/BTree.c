#include <stdio.h>
#include <stdlib.h>
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


/**
 * @brief Get the Max Recursive object
 * è necessario controllare che leftmAX e rightMax non siano nulli prima di fare il compare
 * @param b 
 * @return Item 
 */
Item getMaxRecursive(BTree b){
    if(isEmptyTree(b))
        return NULL;
    else{
        Item value=b->item;
        Item left,right;
        left=getMaxRecursive(b->left);
        right=getMaxRecursive(b->right);
        if(left && compareItem(left,value)>0)
            value=left;
        if(right && compareItem(right,value)>0)
            value=right;
        return value;
    }
}

Item getMaxIterative(BTree b){
    Item max=b->item;
    Stack stack=newStack();
    push(stack,b);
    while(!isEmptyStack(stack)){
        BTree bTemp=top(stack);
        if(compareItem(bTemp->item,max)>0){
            max=bTemp->item;
            //outputItem(max);
        }
        pop(stack);
        if(getRight(bTemp)!=NULL)
            push(stack,getRight(bTemp));
        if(getLeft(bTemp)!=NULL)
            push(stack,getLeft(bTemp));
    }
    return max;
}