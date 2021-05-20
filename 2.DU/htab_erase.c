/* 
*************************************************************************************
* htab_erase.c                                                                      *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module htab_erase.c, with funcion of the same name, which erase the item based on *
* the key, if the item is found and erased returs true if not returns false         *
*************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include "htab_and_item_structures.h"
#include <stdbool.h>
#include <string.h>

bool htab_erase(htab_t * t, htab_key_t key) {
    
    size_t index = (htab_hash_function(key) % t->arr_size);
    struct htab_item *item = t->arr_items[index];
    struct htab_item *prev = NULL;
    bool first = true;
    if (item != NULL) {
        //check if it is the first item in the linked list
        if ((!strcmp(item->pair.key, key)) && first) {
            //need to change head of the linked list to the second item
            t->arr_items[index] = item->next;
            first = false;
            free((char *)item->pair.key);
            free(item);
            t->size--;
            return true;
        }
        //go through the rest of the items
        while (item != NULL) {
            if (!strcmp(item->pair.key, key)) {
                prev->next = item->next;
                free((char *)item->pair.key);
                free(item);
                t->size--;
                return true;
            }
            prev = item;
            item = item->next;
        }
    }
    return false;
}