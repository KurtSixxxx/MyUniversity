#ifndef MATRICENORMALIZZATA
#define MATRICENORMALIZZATA

#include<stdint.h>
#include<stdbool.h>
#include<errno.h>
typedef struct Elem
{
    char filename[FILENAME_MAX];
    size_t n;
    size_t m;
} Elem;

#endif