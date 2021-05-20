#include <stdio.h>
/* 
*************************************************************************************
* io.c                                                                              *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module io.c, implementation of function read-word, reads only max-1 characters and*
* the rest of the word is skipped                                                   *
*************************************************************************************
*/

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int read_word(char *s, int max, FILE *f) {
    int word_length = 0; // read word length
    int c = 0; // variable for characters, int because of EOF
    //bool warning = false;
    //loop to read the non-space characters
    while (((c = fgetc(f)) != EOF) && !(isspace(c))) {
        //printf("%c\n",c);
        if (word_length == max - 1) {
            break;
        }
        s[word_length] = c;
        word_length++;
    }
    s[word_length] = '\0';
    //skip rest of the word if the last read character wasnt EOF or one of isspace characters
    if (c != EOF && !(isspace(c))) {
        //word is longer than max
        do {
            word_length++;
        } while ((c = fgetc(f)) != EOF && !isspace(c));
    }
    //if c is EOF need to return EOF(-1), without this i would always return 0 and create infinite loop
    if (c == EOF) {
        return EOF;
    }
    return word_length;
}
