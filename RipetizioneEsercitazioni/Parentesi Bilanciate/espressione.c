#include <stdio.h>
#include "stack.h"
#include "espressione.h"

int isBalanched(char  *exp){
    Stack stack=newStack();
    if(*exp=='\0')
        return 1;
    for(;exp!='\0';exp++){
        if(isOpen(*exp)){
            printf("\n exp vale %s ",*exp);
            Item item=exp;
            outputItem(item);
            push(stack,item);
        }else if(isClosed(*exp)){
            if(isEmptyStack(stack)){
                return 0;
            }else{
                char* ch=top(stack);
                pop(stack);
                if(!isCorresponding(*ch,*exp)){
                    return 0;
                }
            }
        }
    }
    printf("Print stack");
    printStack(stack);
    return isEmptyStack(stack);
}

int isOpen(char ch){
    if(ch=='(' || ch=='[' || ch=='{')
        return 1;
    return 0;
}

int isClosed(char ch){
    if(ch==')' || ch==']' || ch=='}')
        return 1;
    return 0;
}

int isCorresponding(char ch1,char ch2){
    if(isOpen(ch1) && isClosed(ch2) && ( (ch2 - ch1)==1 || (ch2-ch1)==2) ){
        return 1;
    }
    return 0;
}