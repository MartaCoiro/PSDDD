#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "queue.h"
struct queue
{
    List elements;
};

Queue newQueue(){
    Queue queue=malloc(sizeof(struct queue));
    queue->elements=newList();
    return queue;
}

int isEmptyQueue(Queue queue){
    return isEmpt(queue->elements);
}
int enqueue(Queue queue,Item item){
    return addListTail(queue->elements,item);
}
Item dequeue(Queue queue){
    return removeHead(queue->elements);
}
void printQueue(Queue queue){
    printList(queue->elements);
}
void reverseQueue(Queue queue){
    if(isEmptyQueue(queue))
        return;
    Item item=dequeue(queue);
    reverseQueue(queue);
    enqueue(queue,item);
}
