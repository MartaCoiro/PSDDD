#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"
#include "stack.h"

struct queue{
    Stack s1;
    Stack s2;
};

Queue newQueue(){
    Queue queue=malloc(sizeof(struct queue));
    queue->s1= newStack();
    queue->s2=newStack();
    return queue;
}
int isEmptyQueue(Queue queue){
    return isEmptyStack(queue->s1);
}
/**
 * @brief All'interno del primo stack mettiamo l'elemento 
 * 
 * @param queue 
 * @param item 
 * @return int 
 */
int enqueue(Queue queue,Item item){
    return push(queue->s1,item);
}
/**
 * @brief è importante controllare se lo stack non è vuoto prima di fare la push,
 * in questo modo non andremo a inserire nel secondo stack l'ultimo elmento , cioè quello da eliminare
 * @param queue 
 * @return Item 
 */
Item dequeue(Queue queue){
    Item item;
    if(isEmptyQueue(queue))
        return NULL;
    while(!isEmptyStack(queue->s1)){
        item=top(queue->s1);
        pop(queue->s1);
        if(!isEmptyStack(queue->s1))
            push(queue->s2,item);
    }
    while(!isEmptyStack(queue->s2)){
       Item  item2=top(queue->s2);
        pop(queue->s2);
        push(queue->s1,item2);
    }
    return item;
}

void printQueue(Queue queue){
    printStack(queue->s1);
}