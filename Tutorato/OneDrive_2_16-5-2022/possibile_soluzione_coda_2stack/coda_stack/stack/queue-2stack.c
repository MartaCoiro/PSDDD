#include <stdlib.h>
#include "item.h"
#include "queue-2stack.h"
#include "stack.h"

struct queue
{
	Stack enq;
	Stack deq;
};


Queue newQueue()
{
	Queue q = malloc(sizeof(struct queue));
	q->enq = newStack();
	q->deq = newStack();

	return q;
}


int isEmptyQueue(Queue q) {
	return (isEmptyStack(q->enq) && isEmptyStack(q->deq));
}
void enqueue(Queue q, Item i) {
	push(q->enq,i);
}
Item dequeue(Queue q) {

	if (isEmptyStack(q->deq)) {
		while (!isEmptyStack(q->enq)) {
			Item tmp;
			tmp = top(q->enq);
			push(q->deq,tmp);
			pop(q->enq);
		}
	}
	if (isEmptyStack(q->deq)) return NULL;
	Item toReturn;
	toReturn = top(q->deq);
	pop(q->deq);	
	return toReturn;
}

void reverseQueue(Queue q) {
	if (isEmptyQueue(q)) return;
	Item a;
	a = dequeue(q);
	reverseQueue(q);
	enqueue(q,a);
}
