#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../include/str_list.h"

#define MAX_WORD_LENGTH 50

/*
char *p_words[MAX_WORDS];
int currentPos = -1;
int endPos = -1;
*/

void load_lines_from_file(char* fileName, struct str_list *out_line_list) {
    char str[MAX_WORD_LENGTH];
    char *p_word;
    FILE *fp;
    
    if ((fp = fopen(fileName, "r")) == NULL) {
        printf("Cannot open file %s\n", fileName);
        return;
    }
    
    while (fgets(str, MAX_WORD_LENGTH, fp) != NULL) {
        p_word = (char *) malloc(strlen(str));
        if (!p_word) {
            printf("Out of memory. Last position read %d\n", size(out_line_list));
            return;
        }
        
        // remove newline char
        if (str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0';
        }
        
        strcpy(p_word, str);
        
        add_str(out_line_list, p_word);
    }
    
    fclose(fp);
}

/*
void roll() {
    srand(time(NULL));
    currentPos = rand() % (endPos + 1);    
}

char* get_next_word() {
    if (endPos < 0) {
        return "";
    }
 
    currentPos++;
    if (currentPos > endPos) {
        currentPos = 0;
    }
    
    return p_words[++currentPos];
}
*/
