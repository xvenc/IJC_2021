/* 
* eratosthenes.c
* Řešení IJC-DU1, příklad a), 23.3.2020
* Autor: Václav Korvas ,VUT FIT 1BIT (xkorva03)
* Přeloženo: gcc 10.2.1
* Modul eratosthenes.c s implementaci funkce pro vypocet prvocisel
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "bitset.h"
#include "error.h"
#include "time.h"



void Eratosthenes(bitset_t pole){
    
    unsigned long max_value = bitset_size(pole);
    //step 1: 0 and 1 are not prime numbers
    bitset_setbit(pole,0,1);
    bitset_setbit(pole,1,1);
    
    //step 2: set index to 2 and repeat until the index will be bigger than sqrt(N)
    for (bitset_index_t i = 2; i < (bitset_index_t)sqrt(max_value) ; i++) {
        //locate the smallest index that is equal to zero 0, then i is prime
        if (bitset_getbit(pole,i)==0) {
            //go through all folds of i, and set them to 1
            for (bitset_index_t n = i*i; n < max_value; n+=i) {
                // set index to all folds to 1 they are not prime
                bitset_setbit(pole,n,1);       
            }
        }
    }
}

