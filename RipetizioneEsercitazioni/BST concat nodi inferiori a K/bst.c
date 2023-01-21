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

/**
 * @brief Si rende necessaria un visita inOrder per concatenare gli elmenti in modo orrdinato
 * 
 * @param bst 
 * @param item 
 * @param separator 
 */
void concatItemBSTRecursive(BST bst,Item item,char* separator,char* output){
    if(!isEmptyBST(bst)){
        concatItemBSTRecursive(bst->left,item,separator,output);
        if(compareItem(bst->value,item)<0){
            if(strlen(output)>0){
                strcat(output,separator);
            }
            strcat(output,toString(bst->value));
            //concatItemBSTRecursive(bst->right,item,separator,output);
        }
        concatItemBSTRecursive(bst->right,item,separator,output);
    }
}

char* concatLessThenRecursive(BST bst,Item item,char* separator){
    char* string=malloc(sizeof(char)*200);
    string[0]='\0';
    concatItemBSTRecursive(bst,item,separator,string);
    return string;
}
/**
 * @brief 
 * Si rende necessaria una visita in order per concatenare gli elementi in maniera ordinata
 * @param bst 
 * @param item 
 * @param separator 
 * @return 
 */
char* concatLessThenIterative(BST bst,Item item,char* separator){
    char* output=malloc(sizeof(char)*200);
    output[0]='\0';
    Stack stack=newStack();
    BST current=bst;
    while(!isEmptyStack(stack) || current){
        if(current){
            push(stack,current);
            current=getLeft(current);
        }else{
            current=top(stack);
            if(compareItem(current->value,item)<0){
                if(strlen(output)>0){
                    strcat(output,separator);
                }
                strcat(output,toString(current->value));
            }
            pop(stack);
            current=getRight(current);
        }
    }
    return output;
}