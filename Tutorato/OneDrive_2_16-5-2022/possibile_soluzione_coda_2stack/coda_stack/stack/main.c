#include <stdio.h>
#include "item.h"
#include "stack.h"
#include "queue-2stack.h"

int main()
{


	Queue q;
	q = newQueue();

	Queue q1;
	q1 = newQueue();

	int isEmpty;
	isEmpty = isEmptyQueue(q);
	printf("is empty %d\n",isEmpty);

	int i = 0;
	Item a;
	for(i = 0; i < 5; i++)
	{
		printf("\nInserisci valore : ");
		a = inputItem();
		enqueue(q,a);
		outputItem(a);
	}		

	isEmpty =	isEmptyQueue(q);
	printf("is empty %d\n",isEmpty);

	
	while (!isEmptyQueue(q)) {
		a = dequeue(q);
		outputItem(a);
		enqueue(q1,a);
	}
	printf("Inverto ricorsivamente la coda\n");
	reverseQueue(q1);
	while (!isEmptyQueue(q1)) {
		
		a = dequeue(q1);
		outputItem(a);
	}



}
