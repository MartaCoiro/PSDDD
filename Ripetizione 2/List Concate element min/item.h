typedef void *Item; // per usare void possiamo rifericia ad Item che + un puntotare a void

// il valore di ritorno è come se fosse void*
Item inputItem(); 
void outputItem(Item);
int compareItem(Item ,Item);
char* toString(Item);