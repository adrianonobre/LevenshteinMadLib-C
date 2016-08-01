#define _GNU_SOURCE
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/str_list.h"

void split(char *str, char *delim, str_list *out_word_list) {
	char *running = NULL;
	char *token = NULL;
	char *word = NULL;

	running = strdupa(str);
	while ((token = strsep(&running, delim)) != NULL) {
	    if (strlen(token) > 0) {
	        add_str(out_word_list, token);
	    }
	}

    free(running);
}
