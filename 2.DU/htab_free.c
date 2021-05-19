/* 
*************************************************************************************
* htab_free.c                                                                       *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module htab_free.c, with funcion of the same name, which frees the allocated space*
*************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include "htab_and_item_structures.h"
#include "htab.h"

void htab_free(htab_t * t) {
    htab_clear(t);
    free(t->arr_items);
    free(t);
}