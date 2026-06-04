#include <stdio.h>
#include <string.h>
int main(){

  char arr[24];

    printf("Versione 'for': \n");
    for(char c = 'z'; c >= 'a'; c--){
       if(c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u'){
        continue;
      }
    }
      printf("%c\n", c);
  }

printf("\n");

       printf("Stampa dell'array: \n");
    for(int i = 0; i <= 24; i++){
      printf("%c ", arr[i]);
    }

    return 0;
    }

  

    /*printf("\n");

    printf("Versione 'while': \n");
    char d = 'z';
    while (d >= 'a') {
    if (!(d=='a'||d=='e'||d=='i'||d=='o'||d=='u')) {
        printf("%c\n", d);
    }
    d--;
  }*/

