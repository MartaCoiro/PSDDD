#include <stdio.h>
#include "item.h"
#include "stack.h"

int main(){

    int i=0;
    Stack stack;
    Item item;
    stack=newStack();
     int valPop1=pop(stack);
    printf("La prima pop vale %d\n",valPop1);
    for(i = 0; i < 5; i++)
	{
		printf("Inserisci valore : \n");
		item = inputItem();
		push(stack,item);
        printf("---------\n");
		printStack(stack);
	}	
    /*	
    for(i = 0; i < 6; i++){
		item = top(stack);
		if(item != NULL)
		{
			printf("\nElemento eliminato : ");
			outputItem(item);
		}
		pop(stack);
		printf("\nStack : ");
		printStack(stack);
	}*/
    Item a=top(stack);
    printf("a vale : ");
    outputItem(a);
    int valPop=pop(stack);
    printf("\nLa pop vale %d",valPop);
    printf("\nDopo aver eliminato un elemento\n");
    printStack(stack);
    pop(stack);
    printf("\nDopo aver eliminato un altro elemento\n");
    printStack(stack);
    return 0;
}