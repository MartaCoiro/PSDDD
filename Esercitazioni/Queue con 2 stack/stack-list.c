#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "stack.h"

struct stack
{
    List elements;
};

Stack newStack(){
    Stack stack=malloc(sizeof(struct stack));
    stack->elements=newList();
    return stack;
}

int isEmptyStack(Stack stack){
    return isEmpt(stack->elements);
}
//Push  inserisce
int push(Stack stack,Item item){
    addHead(stack->elements,item);
    return 1;
}
//Pop elimina, se non c'è un item da eliminare in testa alla lista ritona 0
int pop(Stack stack){
    Item item=removeHead(stack->elements);
    if(item==NULL)
        return 0;
    return 1;
}

Item top(Stack stack){
    return getHead(stack->elements);
}

void printStack(Stack stack){
    printList(stack->elements);
}