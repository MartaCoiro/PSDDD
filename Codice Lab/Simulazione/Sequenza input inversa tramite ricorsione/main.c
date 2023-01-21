#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "stack.h"

int main(){

    Stack stack=newStack();
    int i;
    for(i=0;i<4;i++){
        Item item=inputItem();
        push(stack,item);
    }

    printStack(stack);
    printf("\nReverse ");
    int count=0;
    printRecuriveStack(stack,&count);
    printf("%d",count);
    return 0;
}