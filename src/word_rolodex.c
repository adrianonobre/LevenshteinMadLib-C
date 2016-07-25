#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

char *p_words[MAX_WORDS];
int currentPos = -1;
int endPos = -1;

void load_from_file(char* fileName) {
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
            printf("Out of memory. Last position read %d\n", endPos);
            return;
        }
        
        // remove newline char
        if (str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0';
        }
        
        strcpy(p_word, str);
        
        if (endPos + 1 == MAX_WORDS) {
            printf("File too big! Max allowed lines is %d\n", MAX_WORDS);
            return;
        }
        
        p_words[++endPos] = p_word;
    }
    
    fclose(fp);
}

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
