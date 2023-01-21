#include <stdio.h>
#include <stdlib.h>
#include "item.h"
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


/**
 * @brief Get the Max Recursive object
 * è necessario controllare che leftmAX e rightMax non siano nulli prima di fare il compare
 * @param b 
 * @return Item 
 */
Item getMaxRecursive(BTree b){
    if(isEmptyTree(b))
        return NULL;
    else{
        Item result=b->item;
        Item leftMax=getMaxRecursive(b->left);
        Item rightMax=getMaxRecursive(b->right);
        if(leftMax && compareItem(leftMax,result)>0){
            result=leftMax;
        }
        if(rightMax && compareItem(rightMax,result)>0){
            result=rightMax;
        }
        //outputItem(result);
        return result;
    }
}

Item getMaxIterative(BTree b){
    Item max=b->item;
    Stack stack=newStack();
    push(stack,b);
    while(!isEmptyStack(stack)){
        BTree bTemp=top(stack);
        if(compareItem(bTemp->item,max)>0){
            max=bTemp->item;
            //outputItem(max);
        }
        pop(stack);
        if(getRight(bTemp)!=NULL)
            push(stack,getRight(bTemp));
        if(getLeft(bTemp)!=NULL)
            push(stack,getLeft(bTemp));
    }
    return max;
}



int isEqualsTreeRecursive(BTree b1,BTree b2){
    if(isEmptyTree(b1) && isEmptyTree(b2))
        return 1;
    if(isEmptyTree(b1) || isEmptyTree(b2))
        return 0;
    return (compareItem(b1->item,b2->item)==0  
        && isEqualsTreeRecursive(getLeft(b1),getLeft(b2)) && isEqualsTreeRecursive(getRight(b1),getRight(b2)));
    
}
int isEqualsTreeIterative(BTree b1,BTree b2){
    if(isEmptyTree(b1) && isEmptyTree(b2))
        return 1;
    if(isEmptyTree(b1) || isEmptyTree(b2))
        return 0;
    Stack stack1=newStack();
    Stack stack2=newStack();
    push(stack1,b1);
    push(stack2,b2);
    while(!isEmptyStack(stack1) && !isEmptyStack(stack2)){
        BTree bTemp1=top(stack1);
        BTree bTemp2=top(stack2);
        if(compareItem(bTemp1->item,bTemp2->item)!=0)
            return 0;
        pop(stack1);
        pop(stack2);
        if(getRight(bTemp1)!=NULL)
            push(stack1,getRight(bTemp1));
        if(getLeft(bTemp1)!=NULL)
            push(stack1,getLeft(bTemp1));
        if(getRight(bTemp2)!=NULL)
            push(stack2,getRight(bTemp2));
        if(getLeft(bTemp2)!=NULL)
            push(stack2,getLeft(bTemp2));
    }
    return 1;
}

int searchItemRecursive(BTree b,Item item){
    if(isEmptyTree(b))
        return 0;
    return compareItem(b->item,item) || searchItemRecursive(getLeft(b),item) || searchItemRecursive(getRight(b),item);
}

int searchItemIterative(BTree b,Item item){
    if(isEmptyTree(b))
        return 0;
    else{
        Stack stack=newStack();
        push(stack,b);
        while(!isEmptyStack(stack)){
            BTree bTemp=top(stack);
            if(compareItem(bTemp->item,item)==0)
                return 1;
            pop(stack);
        if(getRight(bTemp)!=NULL)
            push(stack,getRight(bTemp));
        if(getLeft(bTemp)!=NULL)
            push(stack,getLeft(bTemp));
        }
        return 0;
    }
}