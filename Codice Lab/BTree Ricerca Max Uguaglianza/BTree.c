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

/*
Pre condizioni:
La funzione prende in ingresso un albero binario e un item  da cercare
nei nodi dell'albero

Post condizioni:
La funzione restituisce 1 se l'item è contenuto in almeno un nodo, 0 altrimenti.
Se l'albero è vuoto, la funzione restituisce 0.
*/
int ricercaItem(BTree btree,Item item){
    if(isEmptyTree(btree))
        return 0;
    if((cmpItem(btree->item,item)==0) || ricercaItem(getLeft(btree),item) || ricercaItem(getRight(btree),item) )  {
        return 1;
    }
}
/*
Pre condizioni:
La funzione prende in ingresso un albero binario

Post condizioni:
La funzione restituisce il valore massimo tra quelli presenti nei nodi
dell'albero, NULL se l'albero è vuoto.
*/
/*
Item maxValueNode(BTree b){
    if(isEmptyTree(b))
        return NULL;
    Item max1,max2,max3;
    max1=b->item;
    if(b->left==NULL && b->right==NULL)
        return b->item;
    if(b->left)
        max2=maxValueNode(b->left);
    if(b->right)
        max3=maxValueNode(b->right);
    if(cmpItem(max2,max3)>=0){
        if(cmpItem(max2,max1)>=0)
            return max2;
        return max1;
    }else{
        if(cmpItem(max3,max1)>=0)
            return max3;
        return max1;
    }
}*/
Item maxValueNode(BTree b){
    if(isEmptyTree(b))
        return NULL;
    else{
        Item value=b->item;
        Item left,right;
        left=maxValueNode(b->left);
        right=maxValueNode(b->right);
        if(left && cmpItem(left,value)>0)
            value=left;
        if(right && cmpItem(right,value)>0)
            value=right;
        return value;
    }
}
/*
Pre condizioni:
La funzione prende in ingresso due alberi binari 

Post condizioni:
La funzione restituisce 1 se i due alberi hanno la stessa struttura
e gli stessi contenuti.
*/
int isEqualsBTree(BTree b1,BTree b2){
    if(isEmptyTree(b1) && isEmptyTree(b2))
        return 1;
    if(isEmptyTree(b1)|| isEmptyTree(b2))
        return 0;
    return cmpItem(b1->item,b2->item)==0 && isEqualsBTree(getLeft(b1),getLeft(b2)) && isEqualsBTree(getRight(b1),getRight(b2));
}