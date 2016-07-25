#define _GNU_SOURCE
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/array.h"

char* split(char *str, char *delim) {
	char *words[10] = NULL;
	char *running = NULL;
	char *token = NULL;
	Array words2;
	
	initArray(&words2, 7);
	
	running = strdupa(str);

    int wordCount = 0;
	while ((token = strsep(&running, delim)) != NULL) {
	    if (strlen(token) > 0) {
	        insertArray(&words2, token);
	        words[wordCount++] = token;
	    }
	}

   	printf("%d\n", wordCount);
   	int i;
   	for (i = 0; i < wordCount; i++) {
   	    printf("-%s-\n", words[i]);
   	}

    free(running);

    freeArray(&words2);

    return words[0];
}
