/* 
*************************************************************************************
* wordcount.c                                                                       *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module wordcount.c, reads from stdin, count the number of ocurrences of each word *
* and also prints the word itself, there is limit 127 characters for each word      *
* longer words will be shorten, and warning will be printed on stderr               *
* If HASHTEST is define while compiling, another hash                               *
* function is used due to the assignment                                            *
*************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "io.h"
#include <string.h>

#define WORD_LENGTH 128

#define SIZE 6959
//From literature i read that the size of hash table should be a prime number
//I chose this number due to amount of unique on numbers in my favourite book
// Harry Potter and The Sorcerers Stone
// The hash table should be big enough to store all the words in their on "bucket"

//if define hash_test it will you this hash function, not the one in the module has_function.c
#ifdef HASHTEST 
    size_t htab_hash_function(htab_key_t str) {
        unsigned long hash = 5381;
        const unsigned char *p;    
        for(p=(const unsigned char*)str; *p!='\0'; p++)
            hash = ((hash << 5) + hash) + *p; /* hash * 33 + c */

        return hash;
    }
#endif /*HASTTEST*/

void print_words(htab_pair_t *data) {
    printf("%s\t%d\n",data->key,data->value);
}

int main(void){

    bool warning = false;
    int delka = 0;
    char word[WORD_LENGTH];
    
    htab_t *tabel = htab_init(SIZE);

    //check if allocation was succesful
    if (tabel == NULL) {
        fprintf(stderr, "ERROR: Couldnt alloc space for hash tabel\n");
        return 1;
    }
    //loop to go through all words from stdin
    while ((delka = read_word(word, WORD_LENGTH, stdin)) != EOF) {
        //add word to hash table
        htab_pair_t *pair = htab_lookup_add(tabel, word);
        //check if adding was succesful
        if (pair == NULL) {
            htab_free(tabel);
            exit(1);
        }
        //if the pair is already in the tabel increment its value
        pair->value++;
        //check if the lenght of the word from stdin wasnt bigger than the limit
        if ((delka > WORD_LENGTH -1) && (!warning)) {
            warning = true;
        }
        //set all the chars in the array to \0
        memset(&word[0],'\0',WORD_LENGTH);
        //printf("%s\n",pair->key);
    }
    //print error only once if the word is longer than 127 characters
    if (warning) {
        fprintf(stderr,"WARNING: Word is longer than %d characters\n",WORD_LENGTH-1);
    }
    //ifdef TEST
    #ifdef MOVETEST
        htab_t *new_table = htab_move(500,tabel);
        htab_free(new_table);
    #endif /*END_IF_MOVETEST*/

    htab_for_each(tabel, &print_words);
    htab_free(tabel);
    return 0;
}