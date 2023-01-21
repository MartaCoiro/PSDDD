#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){
    Queue queue= newQueue();
    int i;
    printf("Inserire elementi nella coda \n");
    for(i=0;i<5;i++){
        Item item=inputItem();
        enqueue(queue,item);
    }
    printf("Ecco la tua coda ");
    printQueue(queue);
    printf("\nDequeue : ");
    /*
    Item it=dequeue(queue);
    printf("\nElemento eliminato : ");
    outputItem(it);
    printf("\nNuova Queue : ");
    printQueue(queue);
    */
   int j;
   for(j=0;j<5;j++){
       if(dequeue(queue)){
           printQueue(queue);
       }
       printf("\n");
   }
    return 0;


}