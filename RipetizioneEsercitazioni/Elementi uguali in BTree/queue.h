#include "item.h"
typedef struct queue *Queue;

Queue newQueue();
int isEsmptyQueue();
int enqueue(Queue,Item);
Item dequeue(Queue);
void printQueue(Queue);