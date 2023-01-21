#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "utils.h"
#include "list.h"


struct list {
	int size;
	struct node *head;
};

struct node {
	Item item;
	struct node *next;
};

List newList() {
    List list = malloc(sizeof(struct list));
    list->size=0;
    list->head=NULL;
    return list;
}

int isEmpty(List list) {
    return (list->size==0);
}

void addHead(List list, Item item) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->item=item;
    new_node->next=list->head;
    list->head=new_node;
    ++(list->size);
}

Item removeHead(List list) {
    if (isEmpty(list))
    		return NULL;
    struct node *temp_node = list->head;
    list->head=temp_node->next;
    Item item=temp_node->item;
    free(temp_node);
    --(list->size);
    return item;
}

Item getHead(List list){
    if (isEmpty(list)) return NULL;
    return list->head->item;
}

int sizeList(List list){
    return list->size;
}

void printList(List list){
    struct node *p;
    for (p=list->head;p!=NULL;p=p->next)
        outputItem(p->item);
}

Item searchItem(List list, char *x){
	struct node *ptr;
	for(ptr=list->head;ptr!=NULL;ptr=ptr->next){
		if(cmpRicerca(ptr->item,x)==0){
				return ptr->item;
			}
		}
}

Item removeListItem(List list, Item item){
	struct node *p, *q;
	Item a;
	if(isEmpty(list)){
		fprintf(stderr,"lista vuota \n");
		return NULL;
	}
	for(p=list->head; p != NULL; q=p,p=p->next){
		if(cmpItem(item,p->item)==0){
			if(p==list->head)
				return removeHead(list);
			else{
				q->next=p->next;
				a=p->item;
				(list->size)--;
				free(p);
				return a;
			}
		}
	}
	return NULL;
}

Item removeListPos(List list, int pos){
	struct node *p, *q;
	Item a;
	int i;
	if(isEmpty(list)){
		fprintf(stderr,"lista vuota \n");
		return NULL;
	}
	for(i=0,p=list->head; p != NULL; q=p,p=p->next, i++){
		if(i==pos){
			if(p==list->head)
				return removeHead(list);
			else{
				q->next=p->next;
				a=p->item;
				(list->size)--;
				free(p);
				return a;
			}
		}
	}
	return NULL;
}

int addListItem(List list, Item item, int pos){
	if(pos<0 || pos> sizeList(list)){
		fprintf(stderr,"posizione non valida");
		return 0;
	}

	if(pos==0){
		addHead(list,item);
		return 1;
	}

	struct node *m,*succ,*n=malloc(sizeof(struct node));
	n->item=item;

	int posizione=0;
	for(m=list->head;m!=NULL && posizione<pos-1;m=m->next,posizione++);
	succ=m->next;
	m->next=n;
	n->next=succ;
	list->size+=1;
	return 1;
}

int addListTail(List list, Item item){
	return addListItem(list,item,sizeList(list));
}

void reverseList(List list)
{
	struct node *prev=NULL;
	struct node *p;
	struct node *temp;
	for(p=list->head;p;prev=p,p=temp)
	{
		temp= p->next;
		p->next=prev;
	}
	list->head=prev;
}

struct node * minimo (struct node *p){
 struct node *i, *min = p;
 for (i = p; i != NULL; i = i->next){
  if ((cmpItem(min->item, i->item)) > 0)
   min = i;
 }
 return min;
}

void sortList(List list){
 struct node *p, *pos_minimo;
 for (p=list->head; p != NULL; p = p-> next){
  pos_minimo = minimo(p);
  swap(&(pos_minimo->item), &(p->item));
 }
}


		
