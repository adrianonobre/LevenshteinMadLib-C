#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/str_list.h"
#include "../include/levenshtein_calculator.h"
#include "../include/strsplit.h"
#include "../include/levenshtein_madlib.h"

int get_random_natural_number(int upper_bound_exclusive);

char *merge(str_list *words);

char *transform_word(char *word, int distance, str_list *dict_word_list);

char *transform(char *sentence, int distance, str_list *dict_word_list) {
    char *new_sentence = NULL;
    char *word = NULL;

    str_list sentence_word_list;
	init(&sentence_word_list, 6);

    split(sentence, " .-!,?\"'", &sentence_word_list);

    int word_index = get_random_natural_number(size(&sentence_word_list));
    word = get_str(&sentence_word_list, word_index);
    word = transform_word(word, distance, dict_word_list);

    change_str(&sentence_word_list, word_index, word);

    new_sentence = merge(&sentence_word_list);
    
	free_list(&sentence_word_list);
	
	return new_sentence;
}

char *transform_word(char *word, int distance, str_list *dict_word_list) {
    int number_of_words = size(dict_word_list);
    char *dict_word;
    
    int start_index = get_random_natural_number(number_of_words);
    int actual_distance;
    int i;
    for (i = 0; i < number_of_words; i++) {
        dict_word = get_str(dict_word_list, (start_index + i) % number_of_words);
        actual_distance = get_distance(word, dict_word);
        if (actual_distance == distance) {
            return dict_word;
        }
    }

    return word;
}

int get_random_natural_number(int upper_bound_exclusive) {
    if (upper_bound_exclusive < 2) {
        printf("get_random_natural_number: upper_bound_exclusive [%d] needs to be greater than 1\n", upper_bound_exclusive);
        exit(1);
    }
    
    srand(time(NULL));
    return rand() % (upper_bound_exclusive);    
}

char *merge(str_list *words) {
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

