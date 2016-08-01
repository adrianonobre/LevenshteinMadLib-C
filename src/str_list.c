#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/str_list.h"


void increase_capacity_if_needed(struct str_list *p_list);
void vrfy_bounds(struct str_list *p_list, int pos);
void vrfy_alloc(void *p, char *caller);

void init(struct str_list *p_list, int initial_capacity) {
    p_list->capacity = initial_capacity;
    p_list->last_idx = -1;
    p_list->data = malloc(sizeof(char *) * p_list->capacity);
    vrfy_alloc(p_list->data, "init");
}

void add_str(struct str_list *p_list, char *str) {
    increase_capacity_if_needed(p_list);

    char *str_copy;
    str_copy = (char *) malloc(strlen(str) + 1);
    vrfy_alloc(str_copy, "add_str");
    strcpy(str_copy, str);

    *(p_list->data + (p_list->last_idx + 1)) = str_copy;
    p_list->last_idx++;
}

char *get_str(struct str_list *p_list, int pos) {
    vrfy_bounds(p_list, pos);
    return *(p_list->data + pos);
}

void change_str(struct str_list *p_list, int pos, char *new_str) {
    vrfy_bounds(p_list, pos);

    char *str_copy;
    str_copy = (char *) malloc(strlen(new_str) + 1);
    vrfy_alloc(str_copy, "add_str");
    strcpy(str_copy, new_str);

    *(p_list->data + pos) = str_copy;
}

int size(struct str_list *p_list) {
    return p_list->last_idx + 1;
}

void free_list(struct str_list *p_list) {
    char *str;
    int i;
    for (i = 0; i < size(p_list); i++) {
        str = get_str(p_list, i);
        free(str);
    }

    free(p_list->data);
    p_list->capacity = 0;
    p_list->last_idx = -1;
    p_list->data = NULL;
}

void increase_capacity_if_needed(struct str_list *p_list) {
    if (p_list->last_idx + 1 == p_list->capacity) {
        p_list->capacity *= 2;
        p_list->data = realloc(p_list->data, sizeof(char *) * p_list->capacity);
        vrfy_alloc(p_list->data, "add_str");
        printf("Increased capacity to %d\n", p_list->capacity);
    }
}

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

