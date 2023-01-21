#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
#include "list.h"
#include "song.h"

struct playlist
{
    char *name;
    List song;
};

Playlist createPlaylist(char* name){
    Playlist playlist=malloc(sizeof(struct playlist));
    playlist->name=strdup(name);
    playlist->song=newList();
    return playlist;
}
void addSong(Playlist playlist,Song song){
    addHead(playlist->song,song);
}

void removeSong(Playlist playlist,char *title){
    Song song=createSong(title,"",0);
    removeListItem(playlist->song,song);
}

void sortedPlaylist(Playlist playlist){
    selectionSortList(playlist->song);
}
void printPlaylist(Playlist playlist){
    printf("Playlist %s \n",playlist->name);
    printList(playlist->song);
}