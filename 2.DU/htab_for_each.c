/* 
*************************************************************************************
* htab_for_each.c                                                                   *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module htab_for_each.c, with funcion of the same name, which calls the funcion in *
* the paramets on each item in the hash table                                       *
*************************************************************************************
*/

#include <stdio.h>
#include "htab.h"
#include "htab_and_item_structures.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)) {
    //go through all the items and call function f on all the items in the hash table
    for (size_t i = 0; i < t->arr_size; i++) {
        for (struct htab_item *item = t->arr_items[i]; item != NULL; item = item->next) {
            htab_pair_t *pair = &item->pair;
            f(pair);
        }
    }
}