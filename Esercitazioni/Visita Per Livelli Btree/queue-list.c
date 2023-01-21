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
int isEsmptyQueue(Queue queue){
    return isEmpt(queue->elements);
}
//l'aggiunta si fa in coda alla lista,
int enqueue(Queue queue,Item item){
    return addListTail(queue->elements,item);
}
// e la rimazione dalla testa della lista
Item dequeue(Queue queue){
    return removeHead(queue->elements);
}

void printQueue(Queue queue){
    printList(queue->elements);
}