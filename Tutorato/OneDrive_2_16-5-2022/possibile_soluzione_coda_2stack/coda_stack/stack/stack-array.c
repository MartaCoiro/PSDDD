#include <stdlib.h>
#include "item.h"
#include "stack.h"
#define MAX_STACK 20

struct stack{
	Item elements[MAX_STACK];
	int top;
};

Stack newStack()
{
	Stack s = malloc(sizeof(struct stack));
	s->top = 0;
	return s;
}

int isEmptyStack(Stack s)
{
	if(s->top == 0)
		return 1;
	else
		return 0;
} 

int push(Stack s, Item item)
{
	if(s->top >= MAX_STACK)
		return 0;
	else
	{
		s->elements[s->top] = item;
		(s->top)++;
		return 1;
	}
}

int pop(Stack s)
{
	if(isEmptyStack(s))
		return 0;
	else
	{
		(s->top)--;
		return 1;
	}
}

Item top(Stack s)
{
	if(isEmptyStack(s))
		return NULL;
	else
		return s->elements[(s->top)-1];
}

void printStack(Stack s)
{
	int i;
	for(i = (s->top)-1; i >= 0; i--)
		outputItem(s->elements[i]);
}