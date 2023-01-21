/*#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){
	int i = 0;
	Queue q;
	Item a;
	q = newQueue();
	for(i = 0; i < 5; i++){
		printf("Inserisci valore :\n");
		a = inputItem();
		enqueue(q,a);
		printQueue(q);
	}
	for(i = 0; i < 6; i++){
		a = dequeue(q);
		if(a != NULL){
			printf("\nElemento eliminato : ");
			outputItem(a);
		}
		printf("\nQueue : ");
		printQueue(q);
	}

}
*/
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
        printQueue(queue);
        printf("\n");

    }

    for(i=0;i<5;i++){
        dequeue(queue);
        printQueue(queue);
        printf("\n");
    }

    return 0;
}
