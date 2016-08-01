#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../include/str_list.h"

#define MAX_WORD_LENGTH 50

void load_lines_from_file(char* fileName, str_list *out_line_list) {
    char str[MAX_WORD_LENGTH];
    FILE *fp;
    
    if ((fp = fopen(fileName, "r")) == NULL) {
        printf("Cannot open file %s\n", fileName);
        return;
    }
    
    while (fgets(str, MAX_WORD_LENGTH, fp) != NULL) {
        // remove newline char
        if (str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0';
        }
        
        add_str(out_line_list, str);
    }
    
    fclose(fp);
}

