#include <stdio.h>

int main(){

    int dati[10]={0,1,2,3,4,5,6,7,8,9};
    printf("%d\n",dati[2]);
    printf("indirizzo = %p \n",dati+2);
    printf("indirizzo = %p \n",&dati[2]);

    printf("dato = %d \n",*dati+2);
    printf("dato = %d \n",dati[2]);


    return 0;
}