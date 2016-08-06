#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include "../include/str_list.h"

#define MAX_WORD_LENGTH 50

int load_lines_from_file(char* fileName, str_list *out_line_list) {
    char str[MAX_WORD_LENGTH];
    FILE *fp;
    
    if ((fp = fopen(fileName, "r")) == NULL) {
        //printf("Cannot open file %s\n", fileName);
        return 0;
    }
    
    while (fgets(str, MAX_WORD_LENGTH, fp) != NULL) {
        // remove newline char
        if (str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0';
        }
        
        add_str(out_line_list, str);
    }
    
    fclose(fp);
    
    if (size(out_line_list) == 0) {
        //printf("Could not open file %s or file was empty.", fileName);
        return 0;
    }
    
    return 1;
}

