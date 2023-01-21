#include <stdio.h>
#include "item.h"
#include "stack.h"
#include "parentesi.h"
#define N 100
int main(){

    char exp[N];
    printf("Inserisci espressione\n");
     scanf("%[^\n]", exp);
     if(isBalanched(exp)){
        printf("Espressione bilanciata");
     }
    else{ 
        printf("Espressione non bilanciata");
    }
    return 0;
}