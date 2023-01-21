#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/**
 * @brief è una visita in  preOrder, si analizza prima la radice e poi i sottoalberi sinistri e destri
 * 
 * @param b 
 * @param item 
 * @param separator 
 * @param output 
 */
void doRecConcatLessThen(BTree b,Item item,char* separator, char* output){
    if(!isEmptyTree(b)){
        if(cmpItem(b->item,item)<0){
            if(strlen(output)>0){
                strcat(output,separator);
            }
            strcat(output,toString(b->item));
            doRecConcatLessThen(b->left,item,separator,output);
            doRecConcatLessThen(b->right,item,separator,output);
        }
        
        //doRecConcatLessThen(b->left,item,separator,output);
        //doRecConcatLessThen(b->right,item,separator,output);
    }
}

/**
 * @brief Allochiamo spazio per la stringa che conterrà la concatenazione
 * 
 * @param b 
 * @param i 
 * @param separator 
 * @return char* 
 */
char * concatNodeLessThen(BTree b,Item i, char *separator){
    char* str=malloc(sizeof(char)*100);
    str[0]='\0';
    doRecConcatLessThen(b,i,separator,str);
    return str;
}

/**
 * @brief Versione Iterativa
 * Anche questa è una visita in preOrdine, solo che per renderla tale è neccesario
 * mettere nello stack prima il sottoalbero destro e poi il sinistro, per avere il sinistro in cima
 * 
 * @param b 
 * @param i 
 * @param separator 
 * @return char* 
 */
char * concatNodeLessThenIerativa(BTree b,Item i,char* separator){
    char* str=malloc(sizeof(char)*100);
    str[0]='\0';
    BTree left,right;
    Stack stack=newStack();
    push(stack,b);
    while(!isEmptyStack(stack)){
        BTree node=top(stack);
        if(cmpItem(node->item,i)<0){
            if(strlen(str)>0){
                strcat(str,separator);
            }
            strcat(str,toString(node->item));
        }
        pop(stack);
        if(getRight(node)!=NULL)
            push(stack,getRight(node));
        if(getLeft(node)!=NULL)
            push(stack,getLeft(node));
    }
     return str;
}