/* 
*************************************************************************************
* htab_bucket_count.c                                                               *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module htab_bucket_count.c, with funcion of the same name, which returns the size *
* of the array of pointer allocated for the items                                   *
*************************************************************************************
*/

#include "htab_and_item_structures.h"
#include "htab.h"

size_t htab_bucket_count(const htab_t * t) {
    return t->arr_size;
}