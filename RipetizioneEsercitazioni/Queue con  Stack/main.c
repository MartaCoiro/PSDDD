
#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){

    int i,q;
    Item elem;
    Queue queue = newQueue();

    for(i=0;i<5;i++){
        printf("Inserisci un elemento: ");
        elem = inputItem();
        if(!enqueue(queue,elem))
            fprintf(stderr,"Impossibile accodare");
    }
	printQueue(queue);
	dequeue(queue);
	printf("\nDopo la dequeue : \n");
	printQueue(queue);
    return 0;
}
