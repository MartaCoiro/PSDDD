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
Item getItem(BST bst){
    if(isEmptyBST(bst))
        return NULL;
    return bst->value;
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

void order(BST bst,List list){
    if(!isEmptyBST(bst)){
        order(bst->left,list);
        addListTail(list,bst->value);
        order(bst->right,list);
    }
}
List listaOrdinata(BST bst){
    List list=newList();
    order(bst,list);
    return list;
}
/**
 * @brief Per inserire in modo gli ordinato gli elementi di un BST in una lista serve una visita in Order
 * 
 * @param bst 
 * @return List 
 */
List listaOrdinataIterativa(BST bst){
    List list=newList();
    Stack stack=newStack();
    BST current=bst;
    while(!isEmptyStack(stack) || current){
        if(current){
            push(stack,current);
            current=getLeft(current);
        }else{
            BST bstTemp=top(stack);
            addListTail(list,bstTemp->value);
            pop(stack);
            current=getRight(bstTemp);
        }
    }
    return list;
}

int nodi(BST b){
	if (isEmptyBST(b))
		return 0;
	else	
		return 1 + nodi(getLeft(b)) + nodi(getRight(b));
}
/**
 * @brief Cerca i due elementi più piccoli, ovviamente vanno cercati nel sottoalbero sinistro visto che è un BST
 * 
 * @param bst 
 * @return Item 
 */
Item primiDueElementi(BST bst){
    if(isEmptyBST(bst) || nodi(bst)<2)
        return NULL;
    static Item items[2];
    BST padre;
    while(getLeft(bst)!=NULL){
        padre=bst;
        bst=getLeft(bst);
    }
    items[0]=getItem(bst);
    if(getRight(bst)!=NULL){
        bst=getRight(bst);
        while(getLeft(bst)!=NULL){
            bst=getLeft(bst);
        }
    }
    else
        bst=padre;
    items[1]=getItem(bst);
    return items;
}

Item ultimiDueElementi(BST bst){
    if(isEmptyBST(bst)|| nodi(bst)<2)
        return NULL;
    static Item items[2];
    BST padre;
    while(getRight(bst)!=NULL){
        padre=bst;
        bst=getRight(bst);
    }
    items[0]=getItem(bst);
    if(getLeft(bst)!=NULL){
        bst=getLeft(bst);
        while(getRight(bst)!=NULL){
            bst=getRight(bst);
        }
    }
    else
        bst=padre;
    items[1]=bst;
    return items;
    
}