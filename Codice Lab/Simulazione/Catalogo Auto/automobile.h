typedef struct automobile *Automobile;

Automobile creaAutomobile(char* targa,int annoImmatricolazione,char* modello,int annoProduzione);
char* getTarga(Automobile);
int getAnnoImmatricolazione(Automobile);
char* getModello(Automobile);
int getAnnoProduzione(Automobile);