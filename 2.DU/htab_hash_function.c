/* 
*************************************************************************************
* htab_hash_function.c                                                              *
* Solution for IJC-DU2, assignment b), 9.4.2020                                     *
* Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)                                    *
* Compiled: gcc 10.2.1                                                              *
* Module htab_size.c, with funcion of the same name, hash which is used to calculate*
* the index in the hash_table                                                       *
*************************************************************************************
*/

#include <stdio.h>
#include <stdint.h>
#include "htab_and_item_structures.h"
#include "htab.h"

size_t htab_hash_function(htab_key_t str) {
    
    uint32_t h=0;     // musí mít 32 bitů
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}


