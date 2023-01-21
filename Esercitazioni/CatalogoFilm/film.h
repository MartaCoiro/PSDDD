typedef struct film *Film;

Film creaFilm(char * ,char *,int ,int);
char * getTitolo(Film);
char *getRegista(Film);
int getDurata(Film);
int getAnnoProduzione(Film);