#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void concatString(BTree b,Item item,char* separator,char* output){
    if(!isEmptyTree(b)){
        concatString(b->left,item,separator,output);
        if(compareItem(b->item,item)<0){
            if(strlen(output)>0){
                strcat(output,separator);
            }
            strcat(output,toString(b->item));
            concatString(b->right,item,separator,output);
        }
       
    }
}

char* concatLessThenRec(BTree b,Item item,char* separator){
    char* str=malloc(sizeof(char)*200);
    str[0]='\0';
    concatString(b,item,separator,str);
    return str;
}