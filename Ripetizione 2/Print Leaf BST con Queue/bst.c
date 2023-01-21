#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "bst.h"
#include "queue.h"

struct node
{
    Item value;
    struct node* left;
    struct node *right;
};

BST newBTS(){
    return NULL;
}
int isEmptyBST(BST bst){
    if(bst==NULL)
        return 1;
    return 0;
}

BST getLeft(BST bst){
    if(isEmptyBST(bst))
        return NULL;
    return bst->left;
}
BST getRight(BST bst){
    if(isEmptyBST(bst))
        return NULL;
    return bst->right;
}

void preOrder(BST b){
    if(!isEmptyBST(b)){
        outputItem(b->value);
        preOrder(b->left);
        preOrder(b->right);
    }
}
void inOrder(BST b){
    if(!isEmptyBST(b)){
        inOrder(b->left);
        outputItem(b->value);
        inOrder(b->right);
    }
}
void postOrder(BST b){
    if(!isEmptyBST(b)){
        postOrder(b->left);
        postOrder(b->right);
        outputItem(b->value);
    }
}

/**
 * @brief Si controlla se l'item coincide con la radice
 * 
 * @param bst 
 * @param item 
 * @return Item 
 */
Item search(BST bst,Item item){
    if(isEmptyBST(bst))
        return NULL;
    int result=compareItem(item,bst->value);
    if(result==0)
        return bst->value;
    else if(result<0)
        return search(getLeft(bst),item);
    else 
        return search(getRight(bst),item);
}

Item min(BST bst){
    if(isEmptyBST(bst))
        return NULL;
    while (getLeft(bst)!=NULL){
        bst=bst->left;
    }
    return  bst->value;
}
Item max(BST bst){
    if(isEmptyBST(bst))
        return NULL;
    while (getRight(bst)!=NULL){
        bst=bst->right;
    }
    return  bst->value;
}
/**
 * @brief 
 * 
 * @param bst è puntatore, e questo serve per far in modo che il bst che passiamo possa essere modificato
 * così da rendere la modifica visibile nel client
 * Dal momento in cui gli passiamo l'indirizzo, per avere l'oggetto rale serve usare l'operatore di deferenzazione
 * @param item  da inserire
 */
void insertBST(BST* bst,Item item){
    if(isEmptyBST(*bst)){
        (*bst)=malloc(sizeof(struct node));
        (*bst)->value=item;
        (*bst)->left=NULL;
        (*bst)->right=NULL;
    }else{
        int result=compareItem(item,(*bst)->value);
        if (result<0){
            insertBST(&((*bst)->left),item);
        }
        else if(result>0){
              insertBST(&((*bst)->right),item);
        }
    }
}

Item deleteBST(BST *bst,Item item){
    if(isEmptyBST(*bst))
        return NULL;
    int result=compareItem(item,(*bst)->value);
    if(result==0){
        if((*bst)->left==NULL){
            BST bTemp;
            Item iresult;
            bTemp=*bst;
            iresult=(*bst)->value;
            *bst=(*bst)->right;
            free(bTemp);
            return iresult;
        }
        else if((*bst)->right==NULL){
            BST bTemp;
            Item iresult;
            bTemp=*bst;
            iresult=(*bst)->value;
            *bst=(*bst)->left;
            free(bTemp);
            return iresult;
        }
        else{
            Item iresult,iMax;
            iresult=(*bst)->value;
            iMax=max((*bst)->left);
            (*bst)->value=iMax;
            deleteBST(&((*bst)->left),iMax);
            return iresult;
        }
    }
    else if(result <0)
        return deleteBST(&((*bst)->left),item);
    else
        return deleteBST(&((*bst)->right),item);

}

int isLeaf(BST bst){
    if(getLeft(bst)==NULL && getRight(bst)==NULL){
        return 1;
    }
    return 0;
}

void printLeafQueue(BST bst){
    if(isEmptyBST(bst))
        return;
    else{
        Queue queue=newQueue();
        enqueue(queue,bst);
        while(!isEsmptyQueue(queue)){
            BST bTemp=dequeue(queue);
            if(isLeaf(bTemp)){
                outputItem(bTemp->value);
            }
            if(getLeft(bTemp)!=NULL)
                enqueue(queue,getLeft(bTemp));
            if(getRight(bTemp)!=NULL)
                enqueue(queue,getRight(bTemp));
        }
    }
}