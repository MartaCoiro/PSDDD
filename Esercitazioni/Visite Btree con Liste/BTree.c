#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
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

void preOrderIterativa(BTree b){
    List list=newList();
    addHead(list,b);
    while(!isEmpty(list)){
        BTree current=getHead(list);
        outputItem(current->item);
        removeHead(list);
        if(getRight(current)!=NULL)
            addHead(list,getRight(current));
        if(getLeft(current)!=NULL)
            addHead(list,getLeft(current));
    }
}
void inOrderIterativa(BTree b){
    List list=newList();
    BTree current=b;
    while(!isEmpty(list) || current){
        if(current){
            current=getLeft(current);
            addHead(list,current);
        }else{
            current=removeHead(list);
            outputItem(current->item);
            addHead(list,getRight(current));
            
        }
    }
    

}