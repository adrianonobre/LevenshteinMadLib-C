#define _GNU_SOURCE
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/str_list.h"

void split(char *str, char *delim, struct str_list *out_word_list) {
	char *running = NULL;
	char *token = NULL;
	char *word = NULL;

	running = strdupa(str);
	while ((token = strsep(&running, delim)) != NULL) {
	    if (strlen(token) > 0) {
	        word = malloc(strlen(token) + 1);
    	    strcpy(word, token);
	        add_str(out_word_list, word);
	    }
	}

	
    int i;
    for(i = 0; i < size(out_word_list); i++) {
        //printf("%s ", get_str(out_word_list, i));
    }
	
    free(running);
}
