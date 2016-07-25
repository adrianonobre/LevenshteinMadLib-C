#define _GNU_SOURCE
#include <stdio.h>

#include "../include/levenshtein_calculator.h"
#include "../include/word_rolodex.h"
#include "../include/strsplit.h"

int main() {
	printf("%d\n", get_distance(" mob", "mob"));
	
	load_from_file("W");

    roll();

//    int i;
//    for (i = 0; i < 200000; i++) {
//	    printf("%d - %s\n", i, get_next_word());
//    }
	
	split("This is a  sentence.", " .-!,?\"'");
	return 0;
}
