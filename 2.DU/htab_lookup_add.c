/* 
*************************************************************************************
* htab_lookup_add.c                                                                 *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module htab_lookup_add.c, with funcion of the same name, which looks for record   *
* if the looking is succesful it returs pointer on this item, but if it doesnt find *
* the item, it alloce space for the new item, and copy the key                      *
*************************************************************************************
*/

#include <stdlib.h>
#include <string.h>
#include "htab_and_item_structures.h"
#include "htab.h"


htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key) {
    
    size_t index = (htab_hash_function(key) % t->arr_size);
    //printf("%ld\n",index);
    struct htab_item *item = t->arr_items[index];
    //htab_pair_t *pair;
    if (item != NULL) {
        //there is item/items on this index, go through them all and check if there are equal to the key
        for (struct htab_item *tmp = t->arr_items[index];tmp != NULL; tmp = tmp->next) {
            if(!(strcmp(tmp->pair.key, key))) {
                return &tmp->pair;
            }
        }
        //there is item/items on this index, but they dont have the same key
        //so i need to create new item
        //save the first item in linked list
        struct htab_item *tmp = t->arr_items[index];
        //allocate space for item
        item = malloc(sizeof(struct htab_item));
        if (item == NULL) {
            return NULL;
        }
        //aloc space for key, the + 1 is for '\0' because strlen doesnt count '\0' to the length
        item->pair.key = malloc(strlen(key) + 1);
        //check if malloc was succesful
        if (item->pair.key == NULL) {
            free(item);
            return NULL;
        }
        //copy key to the item
        strcpy((char *)item->pair.key, key);
        //set the value to 0
        item->pair.value = 0;
        //set the next ptr to the rest of the linked list
        item->next = tmp;
        //put the item on first position in the linked list
        t->arr_items[index] = item;
        t->size++;
        return &item->pair;

    }else {

        //there is no item on this index, so i alloc space
        struct htab_item *new_item = malloc(sizeof(struct htab_item));
        //check if allocation failed
        if(new_item == NULL) {
            return NULL;
        }
        //allocate length of key + 1, because strlen doesnt count \0
        new_item->pair.key = malloc(strlen(key) + 1);
        if(new_item->pair.key == NULL) {
            free(new_item);
            t->arr_items[index] = NULL;
            return NULL;
        }
        //copy key and set its value to 1
        strcpy((char *)new_item->pair.key, key);
        new_item->next = NULL;
        //set the value to 0
        new_item->pair.value = 0;
        //increase the number of items
        t->size++;
        t->arr_items[index] = new_item;
        return &new_item->pair;
    }
}
