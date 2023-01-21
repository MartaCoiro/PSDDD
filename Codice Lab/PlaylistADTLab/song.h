typedef struct song *Song;

Song createSong(char*,char*, int);
char* artist(Song);
char* title(Song);
int duration(Song);