/* 
*****************************************************************************************
* htab_find.c                                                                           *
* Solution for IJC-DU2, assignment b), 9.4.2020                                         *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                        *
* Compiled: gcc 10.2.1                                                                  *
* Module htab_find.c, with funcion of the same name, which returns pointer to the item  *
* if the item with identical key is in the table, if not the funciont returns null      *
*****************************************************************************************
*/

#include <stdio.h>
#include "htab.h"
#include "htab_and_item_structures.h"

htab_pair_t * htab_find(htab_t * t, htab_key_t key) {
    size_t index = htab_hash_function(key) % t->arr_size;
    struct htab_item *item = t->arr_items[index];
    //check if there is an item on the index
    if (item != NULL) {
        //there is item/items on this index, go through them all and check if there are equal to the key
        while (item != NULL) {
            if(!(strcmp(item->pair.key, key))) {
                return &item->pair;
            }
            item = item->next;
        }
    }
    return NULL;
}