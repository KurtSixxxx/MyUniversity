#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    srand(time(0));
    int a = rand()%(20 - 10 + 1) + 10;
    int b = rand()%(20 - 10 + 1) + 10;
    int c = rand()%(20 - 10 + 1) + 10;
    char s1[a];
    char s2[b];
    char s3[c];
    
    for(int i = 0; i < a; i++){
        int type = rand() % 2; // 0 = lettera, 1 = numero
        if(type == 0){
            s1[i] = rand()%('z' - 'a' + 1) + 'a';
        } else {
            s1[i] = rand()%('9' - '0' + 1) + '0';
        }  
    } 
    s1[a] = '\0';
    printf("Stringa 1: %s \n", s1);

    for(int i = 0; i < b; i++){
        int type = rand() % 2;
        if(type == 0){
            s2[i] = rand()%('z' - 'a' + 1) + 'a';
        } else {
            s2[i] = rand()%('9' - '0' + 1) + '0';
        }    
    }  
    s2[b] = '\0';
    printf("Stringa 2: %s \n", s2);

    for(int i = 0; i < c; i++){
        int type = rand() % 2;
        if(type == 0){
            s3[i] = rand()%('z' - 'a' + 1) + 'a';
        } else {
            s3[i] = rand()%('9' - '0' + 1) + '0';
        }  
    } 
    s3[c] = '\0';
    printf("Stringa 3: %s \n", s3);

    printf("\n");

    int cmp1 = strcmp(s1, s2);    
    int cmp2 = strcmp(s1, s3);  
    int cmp3 = strcmp(s2, s3);  
    
    if (cmp1 > 0) {
    printf("%s e' maggiore di %s\n", s1, s2);
    } else if (cmp1 < 0) {
    printf("%s e' maggiore di %s\n", s2, s1);
    } else {
    printf("%s e' uguale %s\n", s1, s2);
    }

    if (cmp2 > 0) {
    printf("%s e' maggiore di %s\n", s1, s3);
    } else if (cmp2 < 0) {
    printf("%s e' maggiore di %s\n", s3, s1);
    } else {
    printf("%s e' uguale %s\n", s1, s3);
    }

    
    printf("\n");
    printf("\n");

   if (cmp1 < 0 && cmp3 < 0) {
    // s1 < s2 < s3
    printf("%s\n%s\n%s\n", s1, s2, s3);
} else if (cmp1 > 0 && cmp2 > 0) {
    // s3 < s2 < s1
    printf("%s\n%s\n%s\n", s3, s2, s1);
} else if (cmp1 > 0 && cmp3 < 0 && cmp2 > 0) {
    // s2 < s3 < s1
    printf("%s\n%s\n%s\n", s2, s3, s1);
} else if (cmp1 < 0 && cmp2 < 0 && cmp3 > 0) {
    // s1 < s3 < s2
    printf("%s\n%s\n%s\n", s1, s3, s2);
} else if (cmp1 > 0 && cmp2 < 0 && cmp3 > 0) {
    // s2 < s1 < s3
    printf("%s\n%s\n%s\n", s2, s1, s3);
} else if (cmp2 > 0 && cmp1 < 0 && cmp3 < 0) {
    // s3 < s1 < s2
    printf("%s\n%s\n%s\n", s3, s1, s2);
}

    return 0;
}