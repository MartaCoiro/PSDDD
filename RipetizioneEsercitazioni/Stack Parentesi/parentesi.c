#include "parentesi.h"
#include "item.h"
#include "stack.h"
int isBalanched(char * exp){
    if(*exp=='\0')
        return 1;
    Stack stack=newStack();
    for(;*exp!='\0';exp++){
        if(isOpen(*exp)){
            Item item=exp;
            push(stack,item);
        }else if(isClosed(*exp)){
            if(isEmptyStack(stack))
                return 0;
            else{
                char* x=top(stack);
                pop(stack);
                if(!isCorresponding(*x,*exp))
                    return 0;
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
int isCorresponding(char ch1, char ch2){
    if(isOpen(ch1) && isClosed(ch2) && ( (ch2-ch1)==1 || (ch2-ch1)==2 ))
        return 1;
    return 0;
}