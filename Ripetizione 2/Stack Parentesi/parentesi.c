#include <stdio.h>
#include "stack.h"
#include "parentesi.h"

//char *exp è solo il puntatore al primo elemento
int isBalanched(char * exp){
    if(*exp=='\0')
        return 1;
    else{
        Stack stack=newStack();
        for(;*exp!='\0';exp++){
            if(isOpen(*exp)){
                Item item=exp;
                push(stack,item);
            }else if(isClosed(*exp)){
                if(isEmptyStack(stack)){
                    return 0;
                }else{
                    char* ch=top(stack);
                    pop(stack);
                    if(!isCorresponding(*ch,*exp))
                        return 0;
                }
            }
        }
        return isEmptyStack(stack);
    }
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
int isCorresponding(char ch1, char ch2){
    if(isOpen(ch1) && isClosed(ch2) && (ch2-ch1==1 || ch2-ch1==2))
        return 1;
    return 0;
}