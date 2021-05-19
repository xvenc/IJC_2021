/* 
* bitset.c
* Řešení IJC-DU1, příklad a), 23.3.2020
* Autor: Václav Korvas ,VUT FIT 1BIT (xkorva03)
* Přeloženo: gcc 10.2.1
* Modul bitset.c s extern definicemi inline funkci
*/

#include <stdio.h>
#include "bitset.h"

#ifdef USE_INLINE

extern inline void bitset_free(bitset_t jmeno_pole);

extern inline unsigned long bitset_size(bitset_t jmeno_pole);

extern inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz);

extern inline int bitset_getbit(bitset_t jmeno_pole, bitset_index_t index);

#endif /*END_IF_USE_INLINE*/