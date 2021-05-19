/* 
* eratosthenes.h
* Řešení IJC-DU1, příklad a), 23.3.2020
* Autor: Václav Korvas ,VUT FIT 1BIT (xkorva03)
* Přeloženo: gcc 10.2.1
* Hlavičkový soubor s definici funkci na vypocete prvocisel
*/

#include <stdio.h>
#include "bitset.h"

#ifndef _ERATOSTHENES_H_
#define _ERATOSTHENES_H_

//function to set bits in array to one if the bits is on non prime number
void Eratosthenes(bitset_t pole);

#endif /*END_IF_ERATOSTHENES_H_*/