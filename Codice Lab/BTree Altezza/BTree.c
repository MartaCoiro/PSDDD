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

void visitaPerLivelli(BTree btree){
    printf("Btree item %s",btree->item);
    if(isEmptyTree(btree)){
        printf("è vuoto");
        return ;
    }
    else{
        BTree left,right;
        Queue queue= newQueue();
        enqueue(queue,btree);
        while(!isEsmptyQueue(queue)){
            //printf("Inizio ciclo\n");
            BTree temp=dequeue(queue);
            //printf(" %s ",btreeTemp->item);
            outputItem(temp->item);
            
            //printf("VALORE %s",btreeTemp->item);
            if((left=getLeft(temp))!=NULL)
                enqueue(queue,left);
            if((right=getRight(temp))!=NULL)
                enqueue(queue,right);
        }
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
    BTree b=btree;
    while(!isEmptyStack(stack) || b){
        if(b){
            push(stack,b);
            b=getLeft(b);
        }else{
            b=top(stack);
            pop(stack);
            outputItem(b->item);
            b=getRight(b);
        }
    }
}
void postOrderIterativo(BTree btree){
    Stack stack= newStack();
    push(stack,btree);
    while(!isEmptyStack(stack))
    {
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