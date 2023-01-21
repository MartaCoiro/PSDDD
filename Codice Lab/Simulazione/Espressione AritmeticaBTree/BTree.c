#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <ctype.h>
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
 
int altezzaBtree(BTree btree){
    int left,right;
    if(isEmptyTree(btree) || isEmptyTree(getLeft(btree)) || isEmptyTree(getRight(btree)))
        return 0;
    else{
        left=altezzaBtree(btree->left);
        right=altezzaBtree(btree->right);
        if(left <right){
            return 1+right;
        }else{
            return 1+left;
        }
    }
}

int nodiBtree(BTree btree){
    int contatore=1;
    if(isEmptyTree(btree))
        return 0;
    else{
        if(!isEmptyTree(btree->left))
            contatore+=nodiBtree(btree->left);
        if(!isEmptyTree(btree->right))
            contatore+=nodiBtree(btree->right);
        return contatore;
    }
}

void preOrderIterativo(BTree btree){
    BTree left,right;
    Stack stack=newStack();
    push(stack,btree);
    while(!isEmptyStack(stack)){
        BTree temp=top(stack);
        outputItem(temp->item);
        pop(stack);
        if((right=getRight(temp))!=NULL)
            push(stack,right);
        if((left=getLeft(temp))!=NULL)
            push(stack,left);
    }
}

void inOrderIterativo(BTree btree){
    Stack stack= newStack();
    BTree current=btree;
    while(!isEmptyStack(stack) || current){
        if(current){
            push(stack,current);
            current=getLeft(current);
        }else{
            current=top(stack);
            pop(stack);
            outputItem(current->item);
            current=getRight(current);
        }
    }
}
void postOrderIterativo(BTree btree){
    Stack stack= newStack();
    push(stack,btree);
    while(!isEmptyStack(stack)){
        BTree b=top(stack);
        if(!isEmptyTree(getRight(b)))
            push(stack,getRight(b));
        if(!isEmptyTree(getLeft(b)))
            push(stack,getLeft(b));
        else{
            outputItem(b->item);
            pop(stack);
            while(b==getLeft(top(stack)) || b==getRight(top(stack))){
                b=top(stack);
                pop(stack);
                outputItem(b->item);
            }
        }
    }
}
/**
 * @brief isdigit funzione delle libreria ctype, verifica se il carattere passato è un nu numero decimale 
 * 
 * @param b 
 * @return int 
 */
int isNumber(BTree b){
    char *itemValue=b->item;
    if(isdigit(*itemValue))
        return 1;
    return 0;
}
/**
 * @brief Si applica lo stesso procedimento per la visita inOrder
 * 
 * @param b 
 */
void espressioneOriginale(BTree b){
    if(!isEmptyTree(b)){
        if(getLeft(b) && getRight(b) && (isNumber(b->left)|| isNumber(b->right)))
            printf("(");
        espressioneOriginale(b->left);
        outputItem(b->item);
        espressioneOriginale(b->right);
        if(getLeft(b) && getRight(b) && (isNumber(b->left)|| isNumber(b->right)))
            printf(")");
    }
}