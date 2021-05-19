/* 
*************************************************************************************
* htab_init.c                                                                       *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module htab_init.c, with funcion of the same name, which allocates space for the  *
* hash_table and array of pointers for the items, returns pointer on allocated space*
* for the table                                                                     *
*************************************************************************************
*/

#include <stdlib.h>
#include <stdio.h>
#include "htab_and_item_structures.h"

//initialize a hash table, malloc space for table
htab_t *htab_init(size_t n){
    
    htab_t *table = malloc(sizeof(htab_t));
    if (table == NULL) {
        return NULL;
    }
    table->arr_size = n;
    table->size = 0;
    table->arr_items = malloc(n * sizeof(struct htab_item*));
    if (table->arr_items == NULL){
        free(table);
        return NULL;
    }
    //inicialize all the pointers in the array to NULL
    for (size_t i = 0; i < n; i++){
        table->arr_items[i] = NULL;
    }
    return table; 
}