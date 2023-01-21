#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "classe.h"
#include "studente.h"




int main(){


	int scelta;
		
	int classe;
	char sezione;
	char *istituto=malloc(sizeof(char)*100);
	
	printf("dammi la classe (1-5)\n");
	scanf("%d",&classe);
	while(classe<1 || classe>5){
	printf("classe non valida\ninserire la classe (1-5)\n");
	scanf("%d",&classe);
	}
	getchar();
	printf("dammi la sezione\n");
	scanf("%c",&sezione);
   getchar();
	printf("dammi l'istituto\n");
	scanf("%[^\n]s",istituto);
	getchar();

	printf("------------------------------------\n\n");
	istituto=realloc(istituto,sizeof(char)*strlen(istituto));
	Classe c=createClasse(classe,sezione,istituto);

	printf("INSERISCI UNO STUDENTE: 1\n");
	printf("RICERCA UNO STUDENTE: 2\n");
	printf("ELIMINA UNO STUDENTE: 3\n");
	printf("STAMPA LA CLASSE: 4\n");
	printf("ORDINA LA CLASSE: 5\n");

do{
	printf("DAMMI UNA SCELTA\n");
	scanf("%d",&scelta);
	
	switch(scelta){

	
	

	case 1: 
			printf("inserire nome cognome data nascita\n");
			addStudente(c,inputItem()); break;
	
	case 2:{
				char *s=malloc(100*sizeof(char));
				printf("inserisci il cognome dello studente da ricercare\n");
				scanf("%s",s);
				s=realloc(s,sizeof(strlen(s)));
				Item studente=searchStudente(c,s);
	
				if(studente==NULL){
						printf("\nnessun studente con queto cognome trovato\n\n");
				}
				else{ 
				printf("\n");
				printStudente(studente);
				printf("\n");
				}
				break;
			 }

	case 3:{
				char *s=malloc(100*sizeof(char));
				printf("inserisci il cognome dello studente da rimuovere\n");
				scanf("%s",s);
				s=realloc(s,sizeof(strlen(s)));
				Item studenteEliminato=searchStudente(c,s);
	
				if(studenteEliminato==NULL){
					printf("\nnessun studente con questo cognome trovato\n\n");
				}
				else{ 
				printf("\nho romosso dall'elenco questo studente:\n");
				printStudente(deleteStudente(c,studenteEliminato));
				printf("\n");
				}
				break;
		}

 	case 4: printClasse(c); break;
	
 	case 5: ordinaClasse(c); break;

	default :	 if(scelta != -1)
          					printf("Scelta non riconosciuta\n");
 	}
}while (scelta != -1);

return 0;
	
}
