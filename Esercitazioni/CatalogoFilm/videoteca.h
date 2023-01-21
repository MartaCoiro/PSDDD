#include "film.h"
#include "item.h"
typedef struct videoteca * Videoteca;

Videoteca creaVideoteca(char *);
void removeFilm(Videoteca,Film);
void aggiungiFilm(Videoteca,Film);
void ordinaPerAnnoProduzione(Videoteca);
int ricercaFilm(Videoteca,Film);
void printVideoteca(Videoteca);