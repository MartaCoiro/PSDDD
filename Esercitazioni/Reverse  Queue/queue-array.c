#include <stdlib.h>
#include "queue.h"
#define MAXQUEUE 10

struct queue
{
    Item elements[MAXQUEUE];
    int head;
    int tail;
};

Queue newQueue(){
    Queue queue=malloc(sizeof(struct queue));
    queue->head=0;
    queue->tail=0;
    return queue;
}

/**
 * @brief 
 * Quando head e tail hanno lo stesso valore , la coda è piena, essenso una coda cricolare
 * @param queue 
 * @return int 
 */
int isEsmptyQueue(Queue queue){
    if(queue->head==queue->tail)
        return 1;
    return 0;
}
int enqueue(Queue queue,Item item){
    if((queue->tail+1)%MAXQUEUE==queue->head) // controlla se è piena
        return 0;
    queue->elements[queue->tail]= item;
    queue->tail = (queue->tail+1)%MAXQUEUE;
    return 1;
}

Item dequeue(Queue queue){
    if(isEsmptyQueue(queue))
        return NULL;
    Item temp = queue->elements[queue->head];
    queue->head= (queue->head+1)%MAXQUEUE;
    return temp;
}

void printQueue(Queue queue){
    int i;
    for(i=queue->head;i!=queue->tail;i=(i+1)%MAXQUEUE)
        outputItem(queue->elements[i]);
}

void reverseQueue(Queue queue){
    if(isEsmptyQueue(queue))
        return;
    Item item=dequeue(queue);
    outputItem(item);
    reverseQueue(queue);
    enqueue(queue,item);    
}