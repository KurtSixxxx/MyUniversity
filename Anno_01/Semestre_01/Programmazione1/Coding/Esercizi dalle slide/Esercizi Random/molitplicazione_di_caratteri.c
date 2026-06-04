#include <stdio.h>
int main(){

    char var;
    printf("Inserire un carattere: ");
    scanf(" %c", &var);

    if(var >= 'A' && var <= 'Z'){
        printf("Maiuscola: %c", var);
    }else if(var >= 'a' && var <= 'z'){
        printf("%d", var);
    }else//(var >= '3' && var <= '10')
    {
    switch(var){

        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        printf("%c moltiplicato per 10: %d", var, (var - '0') * 10);
        break;

        default:
        fprintf(stderr, "Carattere inserito non valido.\n");
        break;
    }
}
return 0;
}