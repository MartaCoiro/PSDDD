#include "song.h"
typedef struct playlist *Playlist;

Playlist createPlaylist(char *);
void addSong(Playlist, Song);
void removeSong(Playlist,char *);
void sortedPlaylist(Playlist);
void printPlaylist(Playlist);