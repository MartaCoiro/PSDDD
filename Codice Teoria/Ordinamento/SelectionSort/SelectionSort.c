#include <stdio.h>

void inputArray(int a[],int n){
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}
void outputArray(int a[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
//ritorna l'indice dove si trova il valore minimo
int minimo(int a[],int n){
    printf("*(a)  = %d mentre a[0] = %d \n",*(a),a[0]);
    int min=0;
    int i;
    for(i=1;i<n;i++){
        if(a[i]<a[min])
            min=i;
    }
    return min;
}
void selectionSort(int a[],int n){
    int i;
    for(i=0;i<n-1;i++){
        //printf("*(a+i) vale %d\n",*(a+i));//stampa il numero
        //printf("Mentre a+i vale %p\n",(a+i));//stampa l'indirizzo
        int min=minimo(a+i,n-i)+i;
        //int min=minimo(&a[i],n-i)+i è equivalente al codice di sopra visto che si passa l'indirizzo
        swap(&a[i],&a[min]);
        //swap(a+i,a+min); è la stessa cosa, dato che è sempre l'indirizzo
    }
}
int main(){
    int array[5];
    int num=5;
    printf("Inserisci dei numeri\n");
    inputArray(array,num);
    printf("Array non ordinato\n");
    outputArray(array,num);
    selectionSort(array,num);
    printf("Array ordinato\n");
    outputArray(array,num);

    return 0;
}