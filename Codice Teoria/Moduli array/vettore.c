#include <stdio.h>
#include "utils.h"

void inputArray(int a[],int n){

    int i;
    for (i=0; i < n; i++){
        int num;
        scanf("%d",&num);
        //printf("Hai secelto %d ",num);
        a[i]=num;
    }
}
    void outputArray(int a[],int n){

        int i;
        for ( i = 0; i < n; i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        
    }
