/* 
*******************************************************************************************
* htab_and_item_structures.h                                                              *
* Solution for IJC-DU2, assignment b), 9.4.2020                                           *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                          *
* Compiled: gcc 10.2.1                                                                    *
* Header file, with declaration of structures for htab_item and for the hash_table itself *
*******************************************************************************************
*/

#include <stdio.h>

#ifndef _HTAB_AND_ITEM_STRUCTURES_
#define _HTAB_AND_ITEM_STRUCTURES_

#include "htab.h"

//structure for item in hash table
struct htab_item {
    htab_pair_t pair;
    struct htab_item* next;
};

//structure for the hash_table
struct htab{
    size_t size;
    size_t arr_size;
    // array of items
    struct htab_item** arr_items;
};

#endif /*END_IF_HTAB_AND_ITEM_STRUCTURES_*/