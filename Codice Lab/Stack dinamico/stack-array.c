#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "stack.h"
#define START_DIM 10 // capienza massima iniziale
#define ADD_DIM 5   //valore da aggiungere alla capienza massima di volta in volta
//Questa soluzione non è dinamicA
struct stack
{
    Item *elements;
    int top;  //indica la posizione del top dello stack, quando sarà pieno non sarà possibile eseguire push
    int dim; //indica quanti elementi può contenere lo stack in ogni momento
};

Stack newStack(){
    Stack stack= malloc(sizeof(struct stack));
    if(stack==NULL){
        return NULL;
    }
    stack->top=0;
    stack->elements=malloc(sizeof(Item)*START_DIM);//allochiamo spazio per l'array di item
    stack->dim=START_DIM;//salviamo in dim la capienza massimo per ora dello stack
    return stack;
   
}

int isEmptyStack(Stack stack){
    if(stack->top==0){
        return 1;
    }
    return 0;
}

int push(Stack stack,Item item){
    Item *temp;
    if(stack->top=stack->dim){ //si verifica se il top ha raggiunto la dimensione massima
        temp=realloc(stack->elements,sizeof(Item)*(stack->dim + ADD_DIM));
        if (temp==NULL){
            return 0;
        }
        else{
            stack->elements=temp; //mettiamo l'array temporaneo nell'array dello stack
            stack->dim+=ADD_DIM;//aggiorniamo il numero di elemneti che può contenere lo stack
        }
    }
    stack->elements[stack->top]=item;
    stack->top++;
    return 1;
}

int pop(Stack stack){
    if(isEmptyStack(stack))
        return 0;
    else{
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

void printStack(Stack stack){
    int i;
    for(i=(stack->top)-1;i>=0;i--){
        outputItem(stack->elements[i]);
    }
}