#include <stdio.h>
#include "stack.h"
#include "parentesi.h"

//char *exp è solo il puntatore al primo elemento
int isBalanched(char *exp){
    Stack stack= newStack();
    if(*exp=='\0')
        return 1;
    for(;*exp!='\0';exp++){
        if(isOpen(*exp)){
            Item item=exp; //item è già un puntatore a void, punterà a quest'indirizzo
            outputItem(item);
            push(stack,item);
        }else if(isClosed(*exp)){
            if(isEmptyStack(stack)){
                return 0;
            }else{
                char *x=top(stack);
                pop(stack);
                if(!isCorresponding(*x,*exp)){
                    return 0;
                }
            }
        }
    }
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