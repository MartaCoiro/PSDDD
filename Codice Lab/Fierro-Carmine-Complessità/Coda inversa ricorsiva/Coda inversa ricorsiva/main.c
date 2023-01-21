#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){

   int i,q;
   Item elem;
   Queue queue = newQueue();
    
   printf("Inserisci elementi: ");
   for(i=0;i<5;i++){
      printf("Inserisci elemento\n"); 
      elem = inputItem();
      if(!enqueue(queue,elem))
         fprintf(stderr,"Impossibile accodare");
      printQueue(queue);
   }
   printQueue(queue);
   printf("\n");
   reverseQueue(queue);
   printQueue(queue);

   return 0;
}
