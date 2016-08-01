#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "../include/str_list.h"
#include "../include/word_file_loader.h"
#include "../include/levenshtein_madlib.h"

#define MAX_SENTENCE_LENGTH 1000

int main() {
    str_list dict_word_list;
	init(&dict_word_list, 100000);
	load_lines_from_file("W", &dict_word_list);
	
    show_title();

    char sentence[MAX_SENTENCE_LENGTH];// = "This is a  sentence.";
    int distance;// = 3;
    while (1) {
        printf("\n(Hit [Enter] to quit)\n");
        printf("Enter a sentence: ");
        fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
        if (strlen(sentence) == 1) {
            break;
        }
        if (sentence[strlen(sentence) - 1] == '\n') {
            sentence[strlen(sentence) - 1] = '\0';
        }
        
        printf("Enter a distance: ");
        scanf("%i", &distance);
        int c;
        while((c = getchar()) != '\n' && c != EOF);

        printf("\n---> MADLIB says: %s\n", transform(sentence, distance, &dict_word_list));
    }
    
	free_list(&dict_word_list);
	
	return 0;
}
