#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "song.h"

Item inputItem(){
    char title[20];
    char artist[20];
    int duration;
    printf("Inserisci titolo:\n");
    scanf("%s",title);
    printf("Inserisci nome artista\n");
    scanf("%s",artist);
    printf("Inserisci durata:\n");
    scanf("%d",&duration);

    return createSong(title,artist,duration);
}

void outputItem(Item item){
    Song song=item;
    printf("\n%s - %s (%d sec.)", artist(song), title(song), duration(song));
}

int compareItem(Item item1,Item item2){
    Song song1=item1;
    Song song2=item2;
    return strcmp(title(song1),title(song2));
}