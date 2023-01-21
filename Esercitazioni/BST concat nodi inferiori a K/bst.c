#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "bst.h"
#include "stack.h"

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
    if(result<0)
        return search(getLeft(bst),item);
    else if(result>0)
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
        int result=compareItem((*bst)->value,item);
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
    int temp=compareItem((*bst)->value,item);
    if(temp==0){
        if((*bst)->left==NULL){
            BST bTemp;
            Item iTemp;
            bTemp=*bst;
            iTemp=(*bst)->value;
            *bst=(*bst)->right;
            free(bTemp);
            return iTemp;
        }
        else if((*bst)->right==NULL){
            BST bTemp;
            Item iTemp;
            bTemp=*bst;
            iTemp=(*bst)->value;
            *bst=(*bst)->left;
            free(bTemp);
            return iTemp;
        }
        else{
            Item iTemp,iMax;
            iTemp=(*bst)->value;
            iMax=max((*bst)->left);
            (*bst)->value=iMax;
            deleteBST(&((*bst)->left),iMax);
            return iTemp;
        }
    }
    else if(temp <0)
        return deleteBST(&((*bst)->left),item);
    else
        return deleteBST(&((*bst)->right),item);
}
/**
 * @brief Dal momento in cui la traccia richiede di avere l'output in maniere ordinata, serve una visita in order
 * dal più piccolo al più grande quindi si analizza prima il BST sinistro, poi la radice e poi il destro
 * 
 * @param bst 
 * @param item 
 * @param separator 
 * @param output 
 */
void concatItemBST(BST bst,Item item,char* separator,char* output){
    if(!isEmptyBST(bst)){
        concatItemBST(bst->left,item,separator,output);
        if(compareItem(bst->value,item)<0){
            if(strlen(output)>0){
                strcat(output,separator);
            }
            strcat(output,toString(bst->value));
            concatItemBST(bst->right,item,separator,output);
        }
    }
}

char* concatItemLessThenRic(BST bst,Item item,char* separator){
   
    char* stringa=malloc(sizeof(char)*100);
    stringa[0]='\0';
    concatItemBST(bst,item,separator,stringa);
    return stringa;
}

char* concatItemLessThenIterativa(BST bst,Item item,char* separator){
    Stack stack=newStack();
    BST currentBst=bst;
    char* str=malloc(sizeof(char)*200);
    str[0]='\0';
    while(!isEmptyStack(stack) || currentBst){
        if(currentBst){
            push(stack,currentBst);
            currentBst=getLeft(currentBst);
        }else{
            currentBst=top(stack);
            if(compareItem(currentBst->value,item)<0){
                if(strlen(str)>0){
                    strcat(str,separator);
                }
                strcat(str,toString(currentBst->value));
            }
            pop(stack);
            currentBst=getRight(currentBst);
        }
    }
    return str;
}
