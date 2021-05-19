/* 
* bitset.h
* Řešení IJC-DU1, příklad a), 6.3.2020
* Autor: Václav Korvas ,VUT FIT 1BIT (xkorva03)
* Přeloženo: gcc 10.2.1
* Hlavičkový soubor s definici maker a inline funkcemi
*/


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "error.h"

#ifndef _BITSET_H_
#define _BITSET_H_

typedef unsigned long bitset_index_t;
 
typedef unsigned long *bitset_t;

#define ULONG_BIT_SIZE (sizeof(bitset_index_t)*CHAR_BIT)


//alloc and create cant be inline because of the scope in functions
//creates array on stack, its inicialised to zero
#define bitset_create(jmeno_pole,velikost) \
    unsigned long (jmeno_pole)[( ((velikost) % ULONG_BIT_SIZE == 0 ) ? ((velikost)/ULONG_BIT_SIZE)+1 : \
    ((velikost)/ULONG_BIT_SIZE)+2)] = {(velikost),0};\
    _Static_assert(((velikost < 1) == 0) && ((velikost > ULONG_MAX/sizeof(unsigned long))==0),"Velikost musi byt vetsi nez 0 a velikost musi byt mensi nez SIZE_MAX/sizeof(unsigned long)");

//allocates array, if fails it returns 0
#define bitset_alloc(jmeno_pole,velikost) assert(((velikost < 1) == 0) && ((velikost > ULONG_MAX/sizeof(unsigned long))==0));\
         bitset_t jmeno_pole = calloc( (((velikost) % ULONG_BIT_SIZE == 0 ) ? ((velikost) / ULONG_BIT_SIZE)+1 : \
                                           ((velikost)/ULONG_BIT_SIZE)+2), sizeof(unsigned long) );\
                                            if (jmeno_pole == NULL) {\
                                              error_exit("bitset_alloc: Chyba alokace paměti\n");\
                                            }\
                                            *(jmeno_pole) = velikost;
   

//inline functions                       
#ifdef USE_INLINE
    
    inline void bitset_free(unsigned long* jmeno_pole) {
        free(jmeno_pole);
    }

    inline unsigned long bitset_size(bitset_t jmeno_pole) {
        return jmeno_pole[0];
    }

    inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz) {
        if (index >= jmeno_pole[0]) {
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n",(unsigned long)(index),(unsigned long)(jmeno_pole[0])-1);
        }else {
            if (vyraz != 0) {
                jmeno_pole[(index/ ULONG_BIT_SIZE)+1] = jmeno_pole[(index / ULONG_BIT_SIZE)+1] | (1UL << (index % ULONG_BIT_SIZE));
            } else {
                jmeno_pole[(index / ULONG_BIT_SIZE)+1] = jmeno_pole[(index/ ULONG_BIT_SIZE)+1] & ~(1UL << (index % ULONG_BIT_SIZE));
            }
        }
    }

    inline int bitset_getbit(bitset_t jmeno_pole, bitset_index_t index) {
        //printf("USING INLINE");
        if (index >= jmeno_pole[0]) {
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n",(unsigned long)(index),(unsigned long)(jmeno_pole[0])-1);
        } else {
            if ((jmeno_pole[(index/ ULONG_BIT_SIZE)+1] & (1UL << (index % ULONG_BIT_SIZE))) != 0) {
                return 1;
            } else {
                return 0;
            }
        }
        return 0;
    }

#else
    
#define SET_ONE(jmeno_pole,index) (jmeno_pole)[((index)/ ULONG_BIT_SIZE)+1] =((jmeno_pole)[((index) / ULONG_BIT_SIZE)+1]) |  (1UL << (index % ULONG_BIT_SIZE))

#define SET_ZERO(jmeno_pole,index) (jmeno_pole)[((index) / ULONG_BIT_SIZE)+1] =((jmeno_pole)[((index)/ ULONG_BIT_SIZE)+1]) & ~(1UL << ((index) % ULONG_BIT_SIZE))


#define bitset_free(jmeno_pole) free(jmeno_pole);

#define bitset_size(jmeno_pole) (jmeno_pole[0])

#define bitset_setbit(jmeno_pole,index,vyraz)do{\
    if ((index) >= bitset_size(jmeno_pole)) {\
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n",(unsigned long)(index),(unsigned long)(bitset_size(jmeno_pole)-1));\
    }else {\
        if(vyraz != 0) { \
            (SET_ONE(jmeno_pole,index));\
        }else {\
            (SET_ZERO(jmeno_pole,index));\
        }\
    }\
    }while (0)  


#define bitset_getbit(jmeno_pole,index) (((index) >= bitset_size(jmeno_pole)) ? \
    (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n",(unsigned long)(index),(unsigned long)(bitset_size(jmeno_pole)-1)),0) :\
    (((jmeno_pole[(index/ ULONG_BIT_SIZE)+1] & (1UL << (index % ULONG_BIT_SIZE))) != 0) ? 1 : 0 ))

#endif /*END_IF_USE_INLINE*/

#endif /*END_IF_BISET_H_*/
