#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "list.h"
#include "item.h"
#define MAX 40

struct queue
{
    Item elements[MAX];
    int head;
    int tail;
};

Queue newQueue(){
    Queue queue=malloc(sizeof(struct queue));
    queue->head=0;
    queue->tail=0;
    return queue;
}
int isEmptyQueue(Queue queue){
    if(queue->head==queue->tail)
        return 1;
    return 0;
}
int enqueue(Queue queue,Item item){
    if((queue->tail)%MAX== queue->head){
        return 0;
    }
    queue->elements[queue->tail]=item;
    queue->tail=(queue->tail +1 )%MAX;
    return 1;
}
int dequeue(Queue queue){
    if(queue->head==queue->tail)
        return NULL;
    Item temp=queue->elements[queue->head];
    queue->head=(queue->head +1)%MAX;
    return temp;
}

void printQueue(Queue queue){
    int i;
    for(i=queue->head;i!=queue->tail;i=(i+1)%MAX){
        outputItem(queue->elements[i]);
    }
}