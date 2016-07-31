#define _GNU_SOURCE
#include <stdio.h>

#include "../include/str_list.h"
#include "../include/word_file_loader.h"
#include "../include/levenshtein_madlib.h"

int main() {
    struct str_list dict_word_list;

	init(&dict_word_list, 100000);

	load_lines_from_file("W", &dict_word_list);

    char *sentence = "This is a  sentence.";
    int distance = 3;

    printf("%s\n", transform(sentence, distance, &dict_word_list));
	
	free_list(&dict_word_list);
	
	return 0;
}
