#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/str_list.h"
#include "../include/levenshtein_calculator.h"
#include "../include/strsplit.h"
#include "../include/levenshtein_madlib.h"

int get_random_natural_number(int upper_bound_exclusive);

char *merge(struct str_list *words);

char *transform(char *sentence, int distance, struct str_list *dict_word_list) {
    char *new_sentence = sentence;

    struct str_list sentence_word_list;
	init(&sentence_word_list, 6);

    split(sentence, " .-!,?\"'", &sentence_word_list);

    int word_index = get_random_natural_number(size(&sentence_word_list));

    change_str(&sentence_word_list, word_index, "bob2");

    new_sentence = merge(&sentence_word_list);
    
	free_list(&sentence_word_list);
	
	return new_sentence;
}

int get_random_natural_number(int upper_bound_exclusive) {
    if (upper_bound_exclusive < 2) {
        printf("get_random_natural_number: upper_bound_exclusive [%d] needs to be greater than 1\n", upper_bound_exclusive);
        exit(1);
    }
    
    srand(time(NULL));
    return rand() % (upper_bound_exclusive);    
}

char *merge(struct str_list *words) {
    char *merged;
    merged = malloc(100); // TODO see what this seize needs to be
    strcpy(merged, "");
    
    int i;
    for(i = 0; i < size(words); i++) {
        strcat(merged, get_str(words, i));
        strcat(merged, " ");
    }
    
    return merged;
}

