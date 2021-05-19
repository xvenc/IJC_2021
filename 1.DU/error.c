/* 
* error.c
* Řešení IJC-DU1, příklad b), 23.3.2020
* Autor: Václav Korvas ,VUT FIT 1BIT (xkorva03)
* Přeloženo: gcc 10.2.1
* Modul error.c s implementaci funkci pro tisk chyboveho hlaseni
*/

#include <stdio.h>
#include "error.h"
#include <stdarg.h>
#include <stdlib.h>



void warning_msg(const char *fmt, ...){ 
    //list of all undeclared arguments 
    va_list all_parametrs;
    va_start(all_parametrs,fmt);
    fprintf(stderr,"CHYBA: ");
    vfprintf(stderr,fmt,all_parametrs);
    va_end(all_parametrs);
}
void error_exit(const char *fmt, ...) {
    va_list all_parametrs;
    va_start(all_parametrs,fmt);
    fprintf(stderr,"CHYBA: ");
    vfprintf(stderr,fmt,all_parametrs);
    va_end(all_parametrs);
    exit(1);
}