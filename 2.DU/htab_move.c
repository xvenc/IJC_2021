/* 
*************************************************************************************
* htab_move.c                                                                       *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module htab_move.c, with funcion of the same name, which moves all the records    *
* from given hash_table to new table, it also clears all the records, but leaves    *
* the table allocated                                                               *
*************************************************************************************
*/

#include <stdlib.h>
#include <stdio.h>
#include "htab.h"
#include "htab_and_item_structures.h"

htab_t *htab_move(size_t n, htab_t *from) {
    
    //inicialaze new tabel
    htab_t * new_tabel = htab_init(n);
    if (new_tabel == NULL) {
        return NULL;
    }
    
    struct htab_item *item = NULL;
    //go through all indexes of array_items
    for (size_t i = 0; i < from->arr_size; i++) {
        item = from->arr_items[i];
        if (item != NULL) {
            while (item != NULL) {
                htab_lookup_add(new_tabel, item->pair.key);
                item = item->next;
            }
        }    
    }
    htab_clear(from);
    return new_tabel;
}