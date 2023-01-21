#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "utils.h"
#include "bst.h"

struct list{
    int size;
    struct node *head;
};

struct node{
    Item value;
    struct node *next;
};

 List newList(){
     List list= malloc(sizeof (struct list));
     list->size=0;
     list->head=NULL; //PUNTA AD UNO STRUCT NODE
     return list;
 }

 int isEmpt(List list){
     /*
     if(list->size==0){
         return 1;
     }
     return 0;*/
     return (list->size==0 ? 1 : 0);
 }
/**
 * @brief 
 * Crreiamo un nuovo nodo, al nodo assegnamo l'item col suo valore, a next assegniamo il puntotare al nodo NULL
 * viso che l'ultimo elemento di una lista ha un puntatore a null
 * quindi dopo aver istanziato la lista in newList, ovviamente lis->head sarà null,
 * dopodichè facciamo in modo ch list-head non punti più a NULL, ma al nodo appena creato
 * @param list 
 * @param Item 
 */
 void addHead(List list,Item Item){
     struct node *n=malloc(sizeof(struct node));
     n->value=Item;
    // quando si crea un nuovo nodo,
    // quello sarà la testa della lista e sarà necessario puntare alla testa precedente
    //next del nuovo nodo deve puntare alla vecchia testa della lista
     n->next=list->head; 
    // serve a cambiare il puntatore alla testa della lista, prima era null
    //altrimenti punta sempre alla testa precedente e quindi si perde in nuovo nodo
     list->head=n;
     (list->size)++;
 }
 Item removeHead(List  list){
        Item a;
        if(isEmpt(list)){
            return NULL;
        }
        struct node *temp=list->head;
        //dato che list->head è un puntatore a un dato di tipo struct node, 
        //crea una copia temporanea della testa della lista, per non perdere il puntatore al nodo successivo
        list->head=temp->next; //si aggiorna la testa della lista facendolo puntare al nodo successivo
        a=temp->value;
        (list->size)--;
        free(temp);
        return a;
 }

 Item getHead(List list){
     if(isEmpt(list)){
        return NULL;
     }
    return (list->head->value);
 }
 
 int sizeList(List list){
     return list->size;
 }
 void printList(List list){
     struct node *n;
     for(n=list->head;n!=NULL;n=n->next){
         outputItem(n->value);
     }
 }
//Dato che non possiamo farci restituire sia l'item trovato che la posizione, passiamo alla funzione 
//un puntatora ad intero che terrà traccia di quante iterate abbiamo fatto, in questo modo possiamo
//avere nel main il valore reale di pos
 Item searchList(List list,Item item, int *pos){
     *pos=0;
     struct node *n;
     for(n=list->head;n!=NULL;n=n->next, (*pos)++){
         if(compareItem(item,n->value)==0){
             return n->value;
         }
     }
    *pos=-1;
    return NULL;
 }

 Item removeListItem(List list,Item item){
     if(isEmpt(list))
        return NULL;
    Item val;
    struct node*p;
    struct node *prev;
    for(p=list->head;p!=NULL;prev=p,p=p->next){
        if(compareItem(item,p->value)==0){
            printf("Ok sono uguali");
            //Bisogna valutare se l'elemento da eliminare si trova in testa alla lista o no
            //se la cancellazioen va fatta in testa alla lista va aggionrata la testa della lista
            if(p==list->head){
                 return removeHead(list);
            }else{
                prev->next=p->next; //si dev agganciare il nodo precedente al nodo successi di quello attuale
                val=p->value;
                free(p);
                (list->size)--;
                return val;
            }
        }
    }
    return NULL;
 }

 Item remvoceListItemPos(List list,int pos){
     if(isEmpt(list))
        return NULL;
    Item val;
    int i=0;
    struct node*p;
    struct node *prev;
    for(p=list->head;p!=NULL;prev=p,p=p->next,i++){
        if(i==pos){
            //Bisogna valutare se l'elemento da eliminare si trova in testa alla lista o no
            //se la cancellazioen va fatta in testa alla lista va aggionrata la testa della lista
            if(p==list->head){
                 return removeHead(list);
            }else{
                prev->next=p->next;
                val=p->value;
                free(p);
                (list->size)--;
                return val;
            }
        }
    }
    return NULL;
 }

 int addListItem(List list,Item item, int pos){
    struct node *n;
    int i;
    if(pos<0 || pos> (list->size))
        return 0;
    if(pos==0){
        addHead(list,item);
        return 1;
    }else{
        for(i=0,n=list->head;i<pos-1;n=n->next,i++);
            struct node *newNode=malloc(sizeof(struct node));
            newNode->value=item;
            newNode->next=n->next;
            n->next=newNode;
            (list->size)++;
            return 1;
    }
 }

 int addListTail(List list,Item item){
     return addListItem(list,item,list->size);
 }

 void reverseList(List list){
    struct node *n, *prev=NULL,*temp;
        for(n=list->head;n!=NULL;prev=n,n=temp){
            temp=n->next;
            n->next=prev;
        }
    list->head=prev;
 }

List cloneList(List list){
    struct node *p;
    List new=newList();
    for(p=list->head;p!=NULL;p=p->next){
        addListTail(list,p->value);
    }
    return new;
}

//Funzioni di Ordinamento
struct node *minimo(struct node *p){
    struct node* min=p;
    for(;p!=NULL;p=p->next){
        if(compareItem(min->value,p->value)>0){
            min=p;
        }
    }
    return min;   
}

void selectionSortList(List list){
    struct node *p,*min;
    for(p=list->head;p!=NULL;p=p->next){
        min=minimo(p);
        swap(&(p->value),&(min->value));
    }
}
int bubbleSortList(List list){
    int i,j,count=0;
    struct node *p ,*temp;
    for(i=1;i<sizeList(list);i++){
        for(p=list->head,temp=p->next,j=0;j<sizeList(list)-i;p=p->next,temp=p->next, j++){
            count++;
            if(compareItem(p->value,temp->value)>0){
                swap(&(p->value),&(temp->value));
            }
        }
    }
    return count;
}
int adaptiveBubbleSortList(List list){
    int i,j,count=0,sorted=0;
    struct node *p,*temp;
    for(i=1;i<sizeList(list) && !sorted;i++){
        sorted=1;
        for(p=list->head,temp=p->next,j=0;j<sizeList(list)-i;p=p->next,temp=p->next,j++){
            count++;
            if(compareItem(p->value,temp->value)>0){
                swap(&(p->value),&(temp->value));
                sorted=0;
            }
        }
    }
    return count;
}

int* concatenaListe(List l1,List l2){
    struct node *p;
    int sizeArray=sizeList(l1)+sizeList(l2);
    int i=0; //indice dell'array in cui conacatenare gli elementi
    int *itemIntero=malloc(sizeof(int));
    int *array=malloc(sizeof(int)*sizeArray+1);
    for(p=l1->head;p!=NULL;p=p->next){
        itemIntero=p->value;
        array[i]=(int)itemIntero;
        i++;
    }
    for(p=l2->head;p!=NULL;p=p->next){
        itemIntero=p->value;
        array[i]=(int)itemIntero;
        i++;
    }
    return array;
}

List  concatenaListe2(List l1,List l2){
    struct node *p,*c;
    List listaNuova=newList();
    for(p=l1->head;p!=NULL;p=p->next){
        addListTail(listaNuova,p->value);
    }
    for(c=l2->head;c!=NULL;c=c->next){
        addListTail(listaNuova,c->value);
    }
    return listaNuova;
}
/**
 * @brief Data una lista per stampare i suoi elementi in modo ordinato 
 * si avvalre di un BST, cioè mette tutti gli elementi in un BST, e li stmpa con un IN ORDER
 * l'inOrder stampa gli elementi del BST dal più piccolo al più grande, facendo : left radice e right
 * 
 * @param list 
 */
void treeSortList(List list){
    BST bst=newBTS();
    struct node* n;
    for(n=list->head;n!=NULL;n=n->next){
        insertBST(&bst,n->value);
    }
    inOrder(bst);
}