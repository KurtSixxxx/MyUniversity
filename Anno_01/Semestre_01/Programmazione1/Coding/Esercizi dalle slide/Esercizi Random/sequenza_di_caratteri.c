/*Codificare in linguaggio C un programma che stampi a ritroso
la sequenza di caratteri da ’a’ a ’z’, ma non le vocali. Codificare due versioni differenti nelle quali si fa uso del costrutto
for e del costrutto while rispettivamente.
*/

#include <stdio.h>
int main(){

    printf("Versione 'for': \n");
    for(char c = 'z'; c >= 'a'; c--){
       if(c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u'){
         //printf("-\n");
          continue;
       }
      printf("%c\n", c);
    }

    printf("\n");

    printf("Versione 'while': \n");
    char d = 'z';
    while (d >= 'a') {
    if (!(d=='a'||d=='e'||d=='i'||d=='o'||d=='u')) {
        printf("%c\n", d);
    }
    d--;
}


return 0;
}