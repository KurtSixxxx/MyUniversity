#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct struct_artist{
    char stage_name[20];
    char full_name[20];
    int year;
}artista;

struct struct_track{
    struct struct_artist artista;
    char title[100];
    float duration;
}album[20];

int main(){
    strcpy(artista.stage_name, "Eminem");
    strcpy(artista.full_name, "Bruce Marshall");
    artista.year=1972;

    for(int i=0;i<20;i++){
        strcpy(album[i].title, "Black magic");
        album[i].duration=60*2+54;
        album[i].artista=artista;
        printf("%s,\n%.2f,\n(%s, %s, %d)", album[i].title, album[i].duration, album[i].artista.stage_name, album[i].artista.full_name, album[i].artista.year);
    }
}