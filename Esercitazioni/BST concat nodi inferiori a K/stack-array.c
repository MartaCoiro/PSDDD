#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "stack.h"
#define MAX 20
//Questa soluzione non è dinamicA
struct stack
{
    Item elements[MAX];
    int top;  //indica la posizione del top dello stack, 
            //quando sarà pieno non sarà possibile eseguire push
};

Stack newStack(){
    Stack stack= malloc(sizeof(struct stack));
    stack->top=0;
    return stack;
   
}

int isEmptyStack(Stack stack){
    if(stack->top==0){
        return 1;
    }
    return 0;
}

int push(Stack stack,Item item){
   if((stack->top)>= MAX ){
        return 0;
   }else{
       stack->elements[stack->top]=item;
       (stack->top)++;
       return 1;
   }
}

int pop(Stack stack){
    if(isEmptyStack(stack))
        return 0;
    else{//top rappresenta sempre l'elemento in cima quindi diminuendo la size , non avremo più accesso a top
        (stack->top)--;
        return 1;
    }
}

Item top(Stack stack){
   if(isEmptyStack(stack)){
       return NULL;
   }else{
       //top rappresenta il successivo, quindi per restituire il top si fa -1
       return stack->elements[(stack->top)-1];
   }
}
/**
 * @brief è necessario scorrere la lista dal top, cioè dalla cima
 * 
 * @param stack 
 */
void printStack(Stack stack){
    int i;
    for(i=(stack->top)-1;i>=0;i--){
        outputItem(stack->elements[i]);
    }
}