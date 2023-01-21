#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "BTree.h"
#include "queue.h"
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
/**
 * @brief L'algoritmo prende la root dell'albero e lo mette nelle coda
 * dopodichè, elimina il nodo e lo salva in una variabile temporanea,
 *  mette nella coda  i nodi  sinistro e destro di temp, in testa alla coda si troverà l'elemento da stampare
 * 
 * @param btree 
 */
void visitaPerLivelli(BTree btree){
    if(isEmptyTree(btree)){
        return ;
    }
    else{
        BTree left,right;
        Queue queue= newQueue();
        enqueue(queue,btree);
        //printf("Prima del while\n");
        while(!isEsmptyQueue(queue)){
            BTree temp=dequeue(queue);
            //printf("Dentro il while\n");
            outputItem(temp->item);
            //printf("Dopo la stampa\n");
            if((left=getLeft(temp))!=NULL)
                enqueue(queue,left);
            if((right=getRight(temp))!=NULL)
                enqueue(queue,right);
        }
    }
}
/**
 * @brief è importante inserire il nodo sinistro dopo quello destro, dal momento in cui deve stare in testa 
 * per essere stampato per primo
 * 
 * @param btree 
 */
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

Item getMaxValuePreOrder(BTree b){
    Item max=b->item;
    Stack stack=newStack();
    push(stack,b);
    while(!isEmptyStack(stack)){
        BTree bTemp=top(stack);
        if(compareItem(bTemp->item,max)>0)
            max=bTemp->item;
        pop(stack);
        if(getRight(bTemp)!=NULL)
            push(stack,getRight(bTemp));
        if(getLeft(bTemp)!=NULL)
            push(stack,getLeft(bTemp));
    }
    return max;
}

Item getMaxValueInOrder(BTree b){
    Item max=b->item;
    BTree current=b;
    Stack stack=newStack();
    while(!isEmptyStack(stack)|| current){
        if(current){
            push(stack,current);
            current=getLeft(current);
        }else{
            current=top(stack);
            if(compareItem(current->item,max)>0)
                max=current->item;
            pop(stack);
            current=getRight(current);
        }
    }
    return max;
}

Item getMaxValueRecursive(BTree b){
    if(!b)
        return NULL;
    Item result=b->item;
    Item leftResult=getMaxValueRecursive(b->left);
    Item rightResult=getMaxValueRecursive(b->right);
    if(leftResult>rightResult)
        result=leftResult;
    if(rightResult>leftResult)
        result=rightResult;
    return result;
}