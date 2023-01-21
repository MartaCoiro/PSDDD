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
//Questa funzione prende un array già ordinato e inserisce un elemento al suo interno
// n è la taglia dell'array ma l'ultimo indice dell'array è i-1
void insertSortedArray(int a[], int *n,int val){
    int i;
    for(i=*n;i>0;i--){
        if(val<a[i-1]){
            a[i]=a[i-1];
            printf("Dentro il for a[i]= %d e i = %d\n",a[i],i);
        }else break; // si blocca perchè dato che è già ordinato, 
                    //se val non è più piccolo dell'ultimo, non deve essere inserito
    }
    printf("a[i]= %d e i = %d\n",a[i],i);
    a[i]=val;
    printf("a[i]= %d e i = %d\n",a[i],i);
    (*n)++;
}

void insertionSort(int a[],int n){
     int i;
    for(i = 1; i < n; )
        insertSortedArray(a,&i,a[i]);
}
void bubbleSort(int a[],int n){
    int i,j;
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }
}
int adaptiveBubbleSort(int a[],int n){
    int i,j;
    int count=0;
    int sorted=0;
    for(i=1;i<n && !sorted;i++){
        sorted=1;
        for(j=0;j<n-i;j++){
            count++;
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]); // se viene effttuato uno scambio sorted diventa 0 altrimenti resta 1
                sorted=0;
            }
        }
    }
    return count;
}
int main(){

    int dim=7;
    int array[dim];
    int val;
    printf("Inserisci valore\n");
    scanf("%d",&val);

    printf("Inserisci array\n");
    inputArray(array,dim);
    //insertSortedArray(array,&dim,val);
    //insertionSort(array,dim);
    int count=adaptiveBubbleSort(array,dim);
    outputArray(array,dim);
    printf("Ci sono stati %d confronti\n",count);

    return 0;
}