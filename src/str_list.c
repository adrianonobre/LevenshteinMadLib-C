#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/str_list.h"

/*
int main() {
    struct str_list word_list;

    init(&word_list, 2);
    add_str(&word_list, "oi");
    add_str(&word_list, "bob");
    add_str(&word_list, "mike");
    printf("%d\n", size(&word_list));
    add_str(&word_list, "alberto");
    add_str(&word_list, "fabio");
    printf("%d\n", size(&word_list));
    
    printf("%s\n", get_str(&word_list, 0));
    printf("%s\n", get_str(&word_list, 3));
    
    free_list(&word_list);
   
    return 0;
}
*/
void vrfy_bounds(struct str_list *p_list, int pos) {
    if (pos < 0) {
        printf("Index out of bounds: index [%d] must be non-negative\n", pos);
        exit(1);
    }
    if (pos > p_list->last_idx) {
        printf("Index out of bounds: %d > %d\n", pos, p_list->last_idx);
        exit(1);
    }
}

void vrfy_alloc(void *p, char *caller) {
    if (p == NULL) {
        printf("Memory allocation failed in [%s]!\n", caller);
        exit(1);
    }
}

void init(struct str_list *p_list, int initial_capacity) {
    p_list->capacity = initial_capacity;
    p_list->last_idx = -1;
    p_list->data = malloc(sizeof(char *) * p_list->capacity);
    vrfy_alloc(p_list->data, "init");
}

void add_str(struct str_list *p_list, char *str) {
    if (p_list->last_idx + 1 == p_list->capacity) {
        p_list->capacity *= 2;
        p_list->data = realloc(p_list->data, sizeof(char *) * p_list->capacity);
        vrfy_alloc(p_list->data, "add_str");
        printf("Increased capacity to %d\n", p_list->capacity);
    }

    *(p_list->data + (p_list->last_idx + 1)) = str;
    p_list->last_idx++;
}

char *get_str(struct str_list *p_list, int pos) {
    vrfy_bounds(p_list, pos);
    return *(p_list->data + pos);
}

void change_str(struct str_list *p_list, int pos, char *new_str) {
    vrfy_bounds(p_list, pos);
    *(p_list->data + pos) = new_str;
}

int size(struct str_list *p_list) {
    return p_list->last_idx + 1;
}

void free_list(struct str_list *p_list) {
    free(p_list->data);
    p_list->capacity = 0;
    p_list->last_idx = -1;
    p_list->data = NULL;
}

