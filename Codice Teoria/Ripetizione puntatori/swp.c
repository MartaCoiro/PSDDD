#include <stdio.h>

void swap(int *, int*);

int main(){
    int a=10;
    int b=20;
    printf("valore e indirizzo di a = %d : %p \n",a,&a);
    printf("valore e indirizzo di b = %d : %p \n",b,&b);

    swap(&a,&b);
    printf("a = %d , b= %d\n",a,b);
    printf("valore e indirizzo di a = %d : %p \n",a,&a);
    printf("valore e indirizzo di b = %d : %p \n",b,&b);

}
void swap(int *x,int *y){
     printf("valore e indirizzo di x = %d : %p \n",*x,&x);
    printf("valore e indirizzo di y = %d : %p \n",*y,&y);

    int tmp=*x;
    *x=*y;
    *y=tmp;
}