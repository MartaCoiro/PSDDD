#include "item.h"
typedef struct stack * Stack;

Stack newStack();
int isEmptyStack(Stack);
int push(Stack,Item); //Inserimento di un elemento
int pop(Stack);      //Cancellazione di un elemento
Item top(Stack);    //ritorna l'elemento in cima allo stack
void printStack(Stack);