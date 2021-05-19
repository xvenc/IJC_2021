/* 
* error.h
* Řešení IJC-DU1, příklad b), 23.3.2020
* Autor: Václav Korvas ,VUT FIT 1BIT (xkorva03)
* Přeloženo: gcc 10.2.1
* Hlavičkový soubor s definicemi funkci s promennym pro tisk chyboveho hlaseni
*/

#include <stdio.h>
#include <stdarg.h>

#ifndef _ERROR_H
#define _ERROR_H

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif /*END_IF_ERROR_H*/
