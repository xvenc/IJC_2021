/* 
* steg-deocode.c
* Řešení IJC-DU1, příklad b), 23.3.2020
* Autor: Václav Korvas ,VUT FIT 1BIT (xkorva03)
* Přeloženo: gcc 10.2.1
* Modul pro dekodovani zpravy, ktera je ulozena na LSB dat, ktere jsou na provciselnem indexu
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "error.h"
#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"


int main(int argc, char **argv){
    //check if there are enough arguments
    if (argc < 2) {
        error_exit("Nebyl zadan soubor!\n");
        return 1;
    }
    char *filename = argv[1];
    struct ppm *pp = ppm_read(filename);
    if (pp == NULL) {
        error_exit("Chybny format\n");
    }
    
    //128 64 32 16 8 4 2 1
    //char rozsah je 0-7
    char letter = 0;

    char index = 0;
    bitset_index_t i = 23;
    bitset_index_t LSB_bit = 0;
    bitset_index_t size = 3*pp->xsize*pp->ysize;

    bitset_alloc(pole,size);
    Eratosthenes(pole);
    
    //loop to go through all items stored in pp->data
    while (i < size) {
        //secure that we only use prime indexes
        if (bitset_getbit(pole,i) == 0) {
            //store the LSB bit from data
            LSB_bit = pp->data[i] & 1;
            //printf("p:%lu in:%d lsb:%lu \n",i,index,LSB_bit);
            //compare the LSB with 1
            if (LSB_bit == 1) {
                letter |= 1 << (index%CHAR_BIT);
                index++;
            } else {
                letter &= ~(1 << (index%CHAR_BIT));
                index++;
            }
        }
        //if the index is 8 that means we have stored all 8 bits(0-7) that creates a letter to print
        if (index == 8) {
            //check if the letter is \n so if we found the last character to print
            if (letter == '\0') {
                break;

                //check if we at the last item of pp->data and if we havent found \n so we error_exit the loop
            }else if(i == size && letter != '\n'){
                error_exit("Zprava neni korektne ukoncena znakem \\n\n");
            }
            //print the letter and assign 0 to index, because we have created one letter and now we start over
            printf("%c",letter);
            index = 0;
        }
        i++;
    }
    ppm_free(pp);
    bitset_free(pole);
    return 0;

}