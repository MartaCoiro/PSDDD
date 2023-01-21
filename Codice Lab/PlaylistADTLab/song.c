#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"

struct song
{
    char *title;
    char *artist;
    int duration;
};

Song createSong(char* title,char* artist, int duration){
    Song song=malloc(sizeof(struct song));
    song->title=strdup(title);
    song->artist=strdup(artist);
    song->duration=duration;
    return song;
}
char* title(Song song){
    char *title=malloc(sizeof(char)*(1+strlen(song->title)));
    strcpy(title,song->title);
    return title;
}
char* artist(Song song){
    char *artist=malloc(sizeof(char)*(1+strlen(song->artist)));
    strcpy(artist,song->artist);
    return artist;
}
int duration(Song song){
    int duration=song->duration;
    return duration;
}