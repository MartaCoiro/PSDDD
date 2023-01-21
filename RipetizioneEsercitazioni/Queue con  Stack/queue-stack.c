#include <stdlib.h>
#include "queue.h"
#include "stack.h"

struct queue
{
    Stack stack1;
    Stack stack2;
};

Queue newQueue(){
    Queue queue=malloc(sizeof(struct queue));
    queue->stack1=newStack();
    queue->stack2=newStack();
    return queue;
}

int isEsmptyQueue(Queue queue){
    return isEmptyStack(queue->stack1);
}
int enqueue(Queue queue,Item item){
    return push(queue->stack1,item);
}
Item dequeue(Queue queue){
    if(isEsmptyQueue(queue))
        return NULL;
    else{
        Item item;
        while(!isEmptyStack(queue->stack1)){
            item=top(queue->stack1);
            pop(queue->stack1);
            if(!isEmptyStack(queue->stack1))
                push(queue->stack2,item);
        }
        while(!isEmptyStack(queue->stack2)){
            Item it=top(queue->stack2);
            pop(queue->stack2);
            push(queue->stack1,it);
        }
        return  item;
    }
}

void printQueue(Queue queue){
    printStack(queue->stack1);
}