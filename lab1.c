#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"
/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName){
   FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }

    char* str = malloc(MAX_LINE_LEN * sizeof(char));
    if (str == NULL) {
        fclose(file);
        return NULL; 
    }
    if (fgets(str, MAX_LINE_LEN, file) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }
    } else {
        free(str);
        str = NULL;
    }

    fclose(file);
    return str; 
    
}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str) {

    if (str == NULL){
        return NULL;
    }
    int originalLength = strlen(str);
    int explodedLength = (originalLength * (originalLength + 1)) / 2;

    char* explode = malloc((explodedLength + 1) * sizeof(char));
    if (explode == NULL) return NULL;

    int outputIndex = 0;

    for (int outerIndex = 0; outerIndex < originalLength; outerIndex++) {
        for (int innerIndex = 0; innerIndex <= outerIndex; innerIndex++) {
            explode[outputIndex++] = str[innerIndex];
        }           

    }

    explode[outputIndex] = '\0'; 
    return explode;
}