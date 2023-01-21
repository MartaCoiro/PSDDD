#include <stdio.h>
#include "item.h"
#include "stack.h"
#include "list.h"

int main(){

    int i=0;
    Stack stack;
    Item item;
    stack=newStack();
     int valPop1=pop(stack);
    printf("La prima pop vale %d\n",valPop1);
    for(i = 0; i < 5; i++){
		printf("Inserisci valore : \n");
		item = inputItem();
		push(stack,item);
        printf("---------\n");
		printStack(stack);
	}
    List list=listToStack(stack);
    printf("\nLista : ");
    printList(list);
    printf("\nStack : ");
    printStack(stack);
    
    return 0;
    
}