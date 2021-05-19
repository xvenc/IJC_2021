/* 
* primes.c
* Řešení IJC-DU1, příklad a), 23.3.2020
* Autor: Václav Korvas ,VUT FIT 1BIT (xkorva03)
* Přeloženo: gcc 10.2.1
* Modul primes.c pro vzestupne vypsani 10 nejvetsich prvocisel mensich nez 200 milionu 
*/

#include <stdio.h>
#include <time.h>
#include "eratosthenes.h"
#include "errno.h"
#include "bitset.h"

#define N 200000000

int main(void){
    
    clock_t start;
    start = clock();
    
    //create array and calculate prime numbers
    bitset_create(p,N);
    Eratosthenes(p);

    //array for the last 10 results, inicializet to 0
    unsigned long array[10] = {0,0};
    int index = 0;
    
    //go through all prime numbers and save the last 10 primes numbers to an array
    for (bitset_index_t i = N-1; i > 0; i--) {
        //check if on index i is 0 so it is prime
        if (bitset_getbit(p,i) == 0){
            array[index] = i;
            index++;
        }
        if (index == 11){
            break;
        }
    }
    //print the last 10 prime numbers from lowest to the highest
    for (int i = 9; i >= 0; i--) {
        printf("%lu\n",array[i]);
    }
    //print the time thats needed to find and print last 10 prime numbers lesser than 200 milion
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
}