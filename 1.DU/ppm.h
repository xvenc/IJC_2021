/* 
* ppm.h
* Řešení IJC-DU1, příklad b), 23.3.2020
* Autor: Václav Korvas ,VUT FIT 1BIT (xkorva03)
* Přeloženo: gcc 10.2.1
* Hlavičkový soubor s definici funkce pro nacteni dat ze souboru a se strukturou pro ulozeni dat
*/

#include <stdio.h>

#ifndef _PPM_H_
#define _PPM_H_
struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);

#endif /*END_IF_PPH_H_*/