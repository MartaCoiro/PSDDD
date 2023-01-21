#include "item.h"

typedef struct queue *Queue;

Queue newQueue();
int isEmptyQueue(Queue);
void enqueue(Queue, Item);
Item dequeue(Queue);
void reverseQueue(Queue);

