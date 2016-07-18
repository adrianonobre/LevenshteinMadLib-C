#include <string.h>
#include <stdio.h>

int get_distance(char *source, char *target) {

    // for all i and j, d[i,j] will hold the Levenshtein distance between
    // the first i characters of s and the first j characters of t
    // note that d has (m+1)*(n+1) values
    int m = strlen(source);
    int n = strlen(target);
    int d[m + 1][n+1];
    int i, j;
    // initialize array
    for (i = 0; i <= m; i++) {
	    for (j = 0; j <= n; j++) {
	    	d[i][j] = 0;
	    }
	}

    // source prefixes can be transformed into empty string by
    // dropping all characters
    for (i = 1; i <= m; i++) {
        d[i][0] = i;
    }

    // target prefixes can be reached from empty source prefix
    // by inserting every character
    for (j = 1; j <= n; j++) {
        d[0][j] = j;
    }

    for (j = 1; j <= n; j++) {
        for (i = 1; i <= m; i++) {
            int substitutionCost;
            if (source[i - 1] == target[j - 1]) {
                substitutionCost = 0;
            } else {
                substitutionCost = 1;
            }
            d[i][j] = min(d[i - 1][j] + 1,
                                 d[i][j - 1] + 1,
                                 d[i - 1][j - 1] + substitutionCost);
        }
    }

    return d[m][n];
}

min(int e1, int e2, int e3) {
	if (e1 < e2 && e1 < e3) {
		return e1;
	} else if (e2 < e1 && e2 < e3) {
		return e2;
	} else {
		return e3;
	}	
}
