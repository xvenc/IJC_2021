/* 
*************************************************************************************
* htab_clear.c                                                                      *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module htab_clear.c, with funcion of the same name, which erase all the records   *
*************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include "htab_and_item_structures.h"
#include "htab.h"


void htab_clear(htab_t * t) {
    //go through all indexes in the array
    for (size_t i = 0; i < t->arr_size; i++){
        struct htab_item *item = t->arr_items[i];
        //go through the linked list of the items and free them all
        for (;item != NULL;) {
            struct htab_item *to_delete = item;
            item = item->next;
            free((char*)to_delete->pair.key);
            free(to_delete);
        }        
        t->arr_items[i] = NULL;
    }
    t->size = 0;
}