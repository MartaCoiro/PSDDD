#include <stdio.h>

int main(){

 
    int num=20;
    int valore=65;
    int *p;
    p=&num;
    
    printf("Indirizzo di  p : %p\n",p);
    printf("Contenuto di *p : %d\n",*p);
    printf("Conenuto di num %d\n",num);
    printf("Indirizzo di num %p\n ",&num);
    printf("Contenuto di valore %d\n",valore);
    printf("Indirizzo di valore %p\n",&valore);
    printf("----------------------\n");
    p=&valore; // non si può fare *P=&num , solo p=&num o *p=&num
    printf("-----------------------------\n");
    printf("Indirizzo di  p : %p\n",p);
    printf("Contenuto di *p : %d\n",*p);
    printf("Conenuto di num %d\n",num);
    printf("Indirizzo di num %p\n ",&num);
    printf("Contenuto di valore %d\n",valore);
    printf("Indirizzo di valore %p\n",&valore);
    *p=27;
    printf("Ora il valore di *p :  %d \n",*p);
    printf("Ora il valore di valore : %d \n",valore);
    /*
    p=&valore; // cambia solo  l'indirizzo ma non il valore
    printf("-------------------\n");
    printf("Indirizzo di  p : %p\n",p);
    printf("Contenuto di *p : %d\n",*p);
    printf("Conenuto di num %d\n",num);
    printf("Indirizzo di num %p\n ",&num);
    printf("Contenuto di valore %d\n",valore);
    printf("Indirizzo di valore %p\n",&valore);
    */

    return 0;
}