#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **array;
    int used;
    int size;
} Array;

void initArray(Array *a, size_t initialSize) {
    a->array = malloc(initialSize * sizeof(char*));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(Array *a, char* element) {
    printf("Adding element: %s, current size: %d\n", element, a->used);
    if (a->used == a->size) {
        a->size *= 2;
        a->array = realloc(a->array, a->size * sizeof(char*));
    }
    
    a->array[a->used] = malloc(strlen(element) + 1);
    if (a->array[a->used] !=NULL) {
        strcpy(a->array[a->used++], element);
    }
}

void freeArray(Array *a) {
    //free(a->array[0]);
    a->array = NULL;
    a->used = a->size = 0;
}
