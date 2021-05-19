/* 
*************************************************************************************
* htab_size.c                                                                       *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module htab_size.c, with funcion of the same name, which returns the size of the  *
* hash_table, which is the number of records in the hash_table                    *
*************************************************************************************
*/

#include "htab_and_item_structures.h"
#include "htab.h"

size_t htab_size(const htab_t * t) {
    return t->size;
}