/* 
* ppm.c
* Řešení IJC-DU1, příklad b), 23.3.2020
* Autor: Václav Korvas ,VUT FIT 1BIT (xkorva03)
* Přeloženo: gcc 10.2.1
* modul ppm.c s implementaci funkci pro nacteni dat z ppm souboru a uvolnenim alokovane struktury
*/

#include <stdio.h>
#include "ppm.h"
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "limits.h"

#define limit (3*8000*8000)

struct ppm * ppm_read(const char * filename){
    
    unsigned xsize = 0,ysize = 0, scale = 0;
    char str[3]; // for reading the format of the image
    int scaned_items = 0; // store number of scanned items
    FILE *soubor = fopen(filename, "r");
    //prepsat error_exit na warning_msg a return NULL
    if (soubor == NULL) {
        warning_msg("Nepodarilo se otevrit soubor\n");
        return NULL;
    }
    //scannig the header of PPM file, fscanf ingnores multiple white spaces
    scaned_items = fscanf(soubor,"%2s %u %u %u",str,&xsize,&ysize,&scale);
    //check for possible errors
    if (scaned_items < 4){
        warning_msg("Nepovedlo se nacist potrebna data pro format P6\n");
        fclose(soubor);
        return NULL;

    } else if (strcmp(str,"P6")) {
        warning_msg("Nejedna se o format P6, zadejte format P6\n");
        fclose(soubor);
        return NULL;

    } else if ((3*xsize*ysize) > limit) {
        warning_msg("Obrazova data prekrocila implementacni limit %d\n",limit);
        fclose(soubor);
        return NULL;

    } else if(scale != 255) {
        warning_msg("Nespravna hodnota pro maximalni hodnotu barvy, mela by byt 255\n");
        fclose(soubor);
        return NULL;

    }
    
    //printf("%s %d %d %d",str,xsize,ysize,scale);
    struct ppm *p = malloc(sizeof(struct ppm)+(3*xsize*ysize));
    if (p == NULL) {
        warning_msg("Nepovedlo se mallocovat data pro strukturu: struct ppm\n");
        fclose(soubor);
        return NULL;
    }
    p->xsize = xsize;
    p->ysize = ysize;
    
    fgetc(soubor); // need to get rid of /n
    int i = 0; // coounter
    int c = 0; // store character from file
    //reading binary data from file
    while ((c = fgetc(soubor)) != EOF) {
        p->data[i] = c;
        i++;
    }
    fclose(soubor);
    return p;
}

void ppm_free(struct ppm *p){
    free(p);
}
/*
int main(int argc, char **argv){
    
    if (argc < 2) {
        fprintf(stderr,"ZADEJ SOUBOR\n");
        return 1;
    }
    char *filename = argv[1];
    struct ppm *pp = ppm_read(filename);
    //128 64 32 16 8 4 2 0 1
    //char rozsah je 0-7
    char message = 0;

    int index = 6;
    message |= 1 << (index);
    index = 0;
    message |= 1 << (index);
    printf("%c\n",message);
    ppm_free(pp);
    return 0;
}
*/